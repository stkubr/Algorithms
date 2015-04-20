//
// Created by stkubr on 14.04.15.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "ConvexHull.h"
#include "../Sorts/SelectionSort.h"
#include <stack>

C_ConvexHull::C_ConvexHull(int N) {
    points2D.resize(N);

    std::default_random_engine gen;
    std::uniform_real_distribution<double> uniDist(0.0, 1.0);

    //points2D = {C_Point2D(1,1),C_Point2D(-1.0,1.0),C_Point2D(-1.0,-1.0),C_Point2D(1.0,-1.0)};
    std::generate(points2D.begin(), points2D.end(),
                  [&uniDist, &gen]() { return C_Point2D(uniDist(gen), uniDist(gen)); });
}

void C_ConvexHull::presortMinYPolar() {
    C_SelectionSort<t_arrayPoints2D> sorter;

    auto y_part_comparator = [](t_arrayPoints2D &data, int i, int j) {
        return (data[i].Y() < data[j].Y()); };

    auto polar_minY_comparator = [](t_arrayPoints2D &data, int i, int j) {
        return (C_Point2D::arg(data[i] - data[0]) < C_Point2D::arg(data[j] - data[0])); };

    sorter.sort(points2D, y_part_comparator);
    sorter.sort(points2D, polar_minY_comparator);
}

std::stack<C_Point2D> C_ConvexHull::calcHull() {
    presortMinYPolar();

    std::stack<C_Point2D> hull;
    hull.push(points2D[0]);
    hull.push(points2D[1]);

    for (int i = 2; i < points2D.size(); ++i) {
        C_Point2D top = hull.top();
        hull.pop();
        while (C_Point2D::CrossProduct(hull.top(), top, points2D[i]) <= 0) {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points2D[i]);
    };

    return hull;
}

void C_ConvexHull::show() {
    std::cout << std::endl;
    for (int i = 0; i < points2D.size(); ++i) {
        std::cout << points2D[i] << std::endl;
    }
}
