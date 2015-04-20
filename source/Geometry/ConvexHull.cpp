//
// Created by stkubr on 14.04.15.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "ConvexHull.h"
#include "../Sorts/SelectionSort.h"


void C_ConvexHull::presortMinYPolar(t_arrayPoints2D &data) {
    C_SelectionSort<t_arrayPoints2D> sorter;

    auto y_part_comparator = [](t_arrayPoints2D &points, int i, int j) {
        return (points[i].Y() < points[j].Y()); };

    auto polar_minY_comparator = [](t_arrayPoints2D &points, int i, int j) {
        return (C_Point2D::arg(points[i] - points[0]) < C_Point2D::arg(points[j] - points[0])); };

    sorter.sort(data, y_part_comparator);
    sorter.sort(data, polar_minY_comparator);
}

std::stack<C_Point2D> C_ConvexHull::calcHull(t_arrayPoints2D & data) {
    presortMinYPolar(data);

    std::stack<C_Point2D> hull;
    hull.push(data[0]);
    hull.push(data[1]);

    for (int i = 2; i < data.size(); ++i) {
        C_Point2D top = hull.top();
        hull.pop();
        while (C_Point2D::CrossProduct(hull.top(), top, data[i]) <= 0) {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(data[i]);
    };

    return hull;
}

void C_ConvexHull::show(t_arrayPoints2D & data) {
    std::cout << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << std::endl;
    }
}
