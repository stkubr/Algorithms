//
// Created by stkubr on 12.04.15.
//

#include "ClientSort.h"
#include <iostream>
#include <iomanip>
#include <random>
#include "../Sorts/SelectionSort.h"
#include "../Sorts/InsertionSort.h"
#include "../Sorts/ShellSort.h"
#include <source/Sorts/MergeSort.h>
#include "../Sorts/Shuffle.h"
#include <algorithm>


C_ClientSort::C_ClientSort(int N) {
    numElements = N;
    data.resize(numElements);

    createData();
}

void C_ClientSort::createData() {
    std::default_random_engine gen;
    std::uniform_real_distribution<double> uniDist(0.0,1.0);

    std::generate(data.begin(),data.end(), [&uniDist,&gen](){return uniDist(gen);});
}

void C_ClientSort::show() {
    std::cout << std::endl;
    for (auto x: data){
        std::cout << std::setprecision(16) << x << std::endl;
    }
    std::cout << std::endl;
}

void C_ClientSort::sort(C_Sort<std::vector<double>> &sortEngine) {
    auto double_comparator = [](std::vector<double> & data, int i, int j) {return (data[i] < data[j]);};
    sortEngine.sort(data, double_comparator);
}

void C_ClientSort::testAllSorts() {
    C_Shuffle<std::vector<double>>::shuffle(data);
    show();
    C_SelectionSort<std::vector<double>> sortEngine1;
    sort(sortEngine1);
    show();

    C_Shuffle<std::vector<double>>::shuffle(data);
    show();
    C_InsertionSort<std::vector<double>> sortEngine2;
    sort(sortEngine2);
    show();

    C_Shuffle<std::vector<double>>::shuffle(data);
    show();
    C_ShellSort<std::vector<double>> sortEngine3;
    sort(sortEngine3);
    show();

    C_Shuffle<std::vector<double>>::shuffle(data);
    show();
    C_MergeSort<std::vector<double>> sortEngine4;
    sort(sortEngine4);
    show();
}