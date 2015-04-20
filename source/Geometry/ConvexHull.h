//
// Created by stkubr on 14.04.15.
//

#ifndef ALGORITHMS_CONVEXHULL_H
#define ALGORITHMS_CONVEXHULL_H

#include <vector>
#include <stack>
#include "Point2D.h"

typedef std::vector<C_Point2D > t_arrayPoints2D;

class C_ConvexHull {
    t_arrayPoints2D points2D;

    void presortMinYPolar();

public:
    C_ConvexHull(int);

    std::stack<C_Point2D> calcHull();

    void show();
};


#endif //ALGORITHMS_CONVEXHULL_H
