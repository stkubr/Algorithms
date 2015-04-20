#include <iostream>
#include <random>
#include <algorithm>

#include "ClassClients/ClientUF.h"
#include "ClassClients/ClientSort.h"
#include "Geometry/ConvexHull.h"

using namespace std;

int main() {
    cout << "Algorithms Library presentation" << endl;

    cout << "UnionFind example:" << endl;
    C_ClientUF clientUF;
    clientUF.test();


    C_ClientSort clientSort(10);
    clientSort.testAllSorts();


    std::vector<C_Point2D > points2D(10);
    std::default_random_engine gen;
    std::uniform_real_distribution<double> uniDist(-1.0, 1.0);
    std::generate(points2D.begin(), points2D.end(),
                  [&uniDist, &gen]() { return C_Point2D(uniDist(gen), uniDist(gen)); });

    C_ConvexHull::show(points2D);
    std::cout  << std::endl;
    std::stack<C_Point2D> hull = C_ConvexHull::calcHull(points2D);
    int hull_size = hull.size();
    for (int i = 0; i < hull_size; ++i) {
        std::cout << hull.top() << std::endl;
        hull.pop();
    }
    C_ConvexHull::show(points2D);

}