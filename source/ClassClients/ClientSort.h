//
// Created by stkubr on 12.04.15.
//

#ifndef ALGORITHMS_CLIENTSORT_H
#define ALGORITHMS_CLIENTSORT_H

#include <vector>
#include <random>

#include "../Sorts/InsertionSort.h"
#include "../Sorts/ShellSort.h"
#include "../Sorts/Shuffle.h"


class C_ClientSort {
private:
    void createData();
    C_Shuffle shuffle;

public:
    int numElements;
    std::vector<double> data;

    C_ClientSort(int N);

    void show();

    void sort(C_Sort & sortEngine);

    void testAllSorts();
};


#endif //ALGORITHMS_CLIENTSORT_H
