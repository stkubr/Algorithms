//
// Created by stkubr on 14.04.15.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include "SelectionSort.h"

template<typename data_t> class C_ShellSort: public C_SelectionSort<data_t> {
private:
    std::vector<int> seq;
public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)> comparator){
        int numElements = data.size();

        if(seq.size() == 0){
            seq = {701, 301, 132, 57, 23, 10, 2, 1}; // Marcin Ciura sequence by default
        }

        for (auto gap: seq) {
            for (int i = gap; i < numElements; ++i) {
                for (int j = i; j >= gap && comparator(data,j,j-gap) ; j -= gap) {
                    this -> exchange(data,j,j-gap);
                }
            }
        }

    }

    void setSequence(std::vector<int> & seq){
        C_ShellSort::seq = seq;
    }
};


#endif //ALGORITHMS_SHELLSORT_H
