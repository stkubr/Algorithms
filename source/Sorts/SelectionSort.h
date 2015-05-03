//
// Created by stkubr on 12.04.15.
//

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <vector>
#include "Sort.h"

template<typename data_t> class C_SelectionSort: public C_Sort<data_t> {
protected:
    static void exchange(data_t &data, int i, int j){
        auto temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)>  comparator){
        int numElements = data.size();
        for (int i = 0; i < numElements; i++) {
            int min = i;
            for (int j = i+1; j < numElements; j++) {
                if (comparator(data,j,min))
                    min = j;
            }
            exchange(data,i,min);
        }
    }
};


#endif //ALGORITHMS_SELECTIONSORT_H
