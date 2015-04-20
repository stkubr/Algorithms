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
    static void presortMinYPolar(t_arrayPoints2D & data);

public:
    static std::stack<C_Point2D> calcHull(t_arrayPoints2D & data);

    static void show(t_arrayPoints2D & data);
};


#endif //ALGORITHMS_CONVEXHULL_H
