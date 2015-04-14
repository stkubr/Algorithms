//
// Created by stkubr on 14.04.15.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include "SelectionSort.h"

class C_ShellSort: public C_SelectionSort {
private:
    std::vector<int> seq;
public:
    virtual void sort(std::vector<double> & data);

    void setSequence(std::vector<int> & seq);
};


#endif //ALGORITHMS_SHELLSORT_H
