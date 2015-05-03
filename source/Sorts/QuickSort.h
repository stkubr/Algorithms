//
// Created by stkubr on 21.04.15.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include "SelectionSort.h"
#include "Shuffle.h"

template<typename data_t> class C_QuickSort: public C_SelectionSort<data_t>{
protected:
    static int partition(data_t & data, std::function<bool(data_t &, int , int)>  comparator, int lo, int hi){
        int i = lo, j = hi + 1;
        for(;;){
            while (comparator(data, ++i, lo))
                if (i == hi) break;

            while (comparator(data, lo, --j))
                if (j == lo) break;

            if (i >= j) break;
            C_QuickSort::exchange(data, i, j);
        }
        C_QuickSort::exchange(data, lo, j);
        return j;
    }

    static void sort(data_t & data, std::function<bool(data_t &, int , int)>  comparator, int lo, int hi){
        if(hi <= lo) return;
        int j = partition(data, comparator, lo, hi);
        sort(data, comparator, lo, j-1);
        sort(data, comparator, j+1, hi);
    }

public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)>  comparator){
        C_Shuffle<data_t>::shuffle(data);
        sort(data, comparator, 0, data.size() - 1);
    }
};

#endif //ALGORITHMS_QUICKSORT_H
