//
// Created by stkubr on 20.04.15.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H


#include "Sort.h"

template<typename data_t> class C_MergeSort: public C_Sort<data_t> {
protected:
    static void merge(data_t & data, data_t & data_aux, int lo, int mid, int hi,
                      std::function<bool(data_t &, int , int)> & comparator){
        for (int k = lo; k <= hi ; ++k) {
            data_aux[k] = data[k];
        }

        int i=lo, j=mid+1;
        for (int k = lo; k <= hi ; ++k) {
            if     (i > mid)                  data[k] = data_aux[j++];
            else if(j > hi)                   data[k] = data_aux[i++];
            else if(comparator(data_aux,j,i)) data[k] = data_aux[j++];
            else                              data[k] = data_aux[i++];
        }
    }

    static void sort(data_t & data, data_t & data_aux, int lo, int hi,
                     std::function<bool(data_t &, int , int)> & comparator){
        if (hi <= lo) return;
        int mid = lo + (hi - lo)/2;
        sort(data, data_aux, lo, mid, comparator);
        sort(data, data_aux, mid+1, hi, comparator);
        merge(data, data_aux, lo, mid, hi, comparator);
    }

public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)> comparator){
        data_t data_aux(data.size());
        sort(data, data_aux, 0, data.size()-1, comparator);
    }
};


#endif //ALGORITHMS_MERGESORT_H
