//
// Created by stkubr on 12.04.15.
//

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <vector>
#include "Sort.h"

class C_SelectionSort: public C_Sort {
protected:
    void exchange(std::vector<double> &data, int i, int j);

    bool less(double v, double w);

public:
    void sort(std::vector<double> & data);

};


#endif //ALGORITHMS_SELECTIONSORT_H
