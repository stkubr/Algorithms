//
// Created by stkubr on 20.04.15.
//

#ifndef ALGORITHMS_POINT2D_H
#define ALGORITHMS_POINT2D_H

#include <cmath>
#include <iostream>

class C_Point2D {
private:
    double x,y;

public:
    C_Point2D(){
        C_Point2D::x=0;
        C_Point2D::y=0;
    }

    C_Point2D(double x, double y){
        C_Point2D::x=x;
        C_Point2D::y=y;
    }

    C_Point2D& operator=(const C_Point2D& right) {
        if (this == &right) {
            return *this;
        }

        x = right.x;
        y = right.y;
        return *this;
    }

    const C_Point2D operator+(const C_Point2D& right) {
        return C_Point2D((this->x + right.x),(this->y + right.y));
    }

    const C_Point2D operator-(const C_Point2D& right) {
        return C_Point2D((this->x - right.x),(this->y - right.y));
    }

    friend std::ostream &operator<<( std::ostream &output,
                                     const C_Point2D &inst){
        output << inst.x << "," << inst.y;
        return output;
    }

    static int CrossProduct(C_Point2D a, C_Point2D b, C_Point2D c){
        double area2 = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
        if      (area2 < 0) return -1;
        else if (area2 > 0) return +1;
        else                return 0;
    }

    static double arg(C_Point2D a){
        if (a.x < 0 && a.y >= 0) return M_PI + atan(a.y/a.x);
        if (a.x < 0 && a.y < 0) return -M_PI + atan(a.y/a.x);
        if (a.x > 0) return atan(a.y/a.x);
        if (a.y > 0) return M_PI/2.0 - atan(a.x/a.y); // arccot
        if (a.y < 0) return -M_PI/2.0 - atan(a.x/a.y); // arccot
        else return 0;
    }

    double X(){return C_Point2D::x;}
    double Y(){return C_Point2D::y;}
};

#endif //ALGORITHMS_POINT2D_H
