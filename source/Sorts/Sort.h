//
// Created by stkubr on 12.04.15.
//

#ifndef ALGORITHMS_SORT_H
#define ALGORITHMS_SORT_H

#include <vector>
#include <functional>

template<typename data_t> class C_Sort {
public:
    virtual void sort(data_t & data, std::function<bool(data_t &, int , int)> comparator)=0;
};

#endif //ALGORITHMS_SORT_H
