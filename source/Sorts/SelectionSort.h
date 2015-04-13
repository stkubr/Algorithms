//
// Created by stkubr on 12.04.15.
//

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <vector>

class C_SelectionSort {
protected:
    void exchange(double, double);

    bool less(double v, double w);

public:
    void sort(std::vector<double> & data);

};


#endif //ALGORITHMS_SELECTIONSORT_H
