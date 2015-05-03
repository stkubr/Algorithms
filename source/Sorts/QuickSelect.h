//
// Created by stkubr on 03.05.15.
//

#ifndef ALGORITHMS_QUICKSELECT_H
#define ALGORITHMS_QUICKSELECT_H


#include "Shuffle.h"
#include "QuickSort.h"

template<typename data_t> class C_QuickSelect: public C_QuickSort<data_t> {
public:
    static auto select(data_t & data, std::function<bool(data_t &, int , int)> comparator, int k){
        C_Shuffle<data_t>::shuffle(data);
        int lo = 0;
        int hi = data.size() - 1;
        while(hi > lo){
            int j = C_QuickSelect::partition(data, comparator, lo, hi);
            if (j < k) lo = j + 1;
            else if (j > k) hi = j - 1;
            else return data[k];
        }
        return data[k];
    }
};


#endif //ALGORITHMS_QUICKSELECT_H
