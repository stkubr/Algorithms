//
// Created by stkubr on 14.04.15.
//

#include <iostream>
#include "ShellSort.h"

void C_ShellSort::sort(std::vector<double> &data) {
    int numElements = data.size();

    if(seq.size() == 0){
        seq = {701, 301, 132, 57, 23, 10, 2, 1}; // Marcin Ciura sequence by default
    }

    for (auto gap: seq) {
        for (int i = gap; i < numElements; ++i) {
            std::cout << i << std::endl;
            for (int j = i; j >= gap && less(data[j],data[j-gap]) ; j -= gap) {
                std::cout <<  " " << j << std::endl;
                exchange(data,j,j-gap);
            }
        }
    }

};

void C_ShellSort::setSequence(std::vector<int> &seq) {
    C_ShellSort::seq = seq;
}