//
// Created by stkubr on 13.04.15.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include "SelectionSort.h"

template<typename data_t> class C_InsertionSort: public C_SelectionSort<data_t> {

public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)> comparator){
        int numElements = data.size();
        for (int i = 0; i < numElements; ++i) {
            for (int j = i; j > 0; --j) {
                if(comparator(data,j,j-1))
                    this -> exchange(data,j,j-1);
                else break;
            }
        }
    }
};

#endif //ALGORITHMS_INSERTIONSORT_H
