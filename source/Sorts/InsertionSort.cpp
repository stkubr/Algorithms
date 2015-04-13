//
// Created by stkubr on 13.04.15.
//

#include "InsertionSort.h"

void C_InsertionSort::sort(std::vector<double> &data) {
    int numElements = data.size();
    for (int i = 0; i < numElements; ++i) {
        for (int j = i; j > 0; --j) {
            if(less(data[j],data[j-1]))
                exchange(data,j,j-1);
            else break;
        }
    }
}