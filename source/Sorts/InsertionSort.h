//
// Created by stkubr on 13.04.15.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include "SelectionSort.h"

class C_InsertionSort: public C_SelectionSort {

public:
    virtual void sort(std::vector<double> & data);

};


#endif //ALGORITHMS_INSERTIONSORT_H
