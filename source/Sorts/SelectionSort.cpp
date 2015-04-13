//
// Created by stkubr on 12.04.15.
//

#include <iostream>
#include "SelectionSort.h"

void C_SelectionSort::sort(std::vector<double> &data) {
    int numElements = data.size();
    for (int i = 0; i < numElements; i++) {
        int min = i;
        for (int j = i+1; j < numElements; j++) {
            if (less(data[j],data[min]))
                min = j;
        }
        exchange(data,i,min);
    }
}

void C_SelectionSort::exchange(std::vector<double> &data, int i, int j) {
    double temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

bool C_SelectionSort::less(double v, double w) {
    return (v < w);
}