//
// Created by stkubr on 12.04.15.
//

#include "ClientSort.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

C_ClientSort::C_ClientSort(int N) {
    numElements = N;
    data.resize(numElements);

    std::default_random_engine gen;
    std::uniform_real_distribution<double> uniDist(0.0,1.0);

    std::generate(data.begin(),data.end(), [&uniDist,&gen](){return uniDist(gen);});
}

void C_ClientSort::show() {
    for (auto x: data){
        std::cout << std::setprecision(16) << x << std::endl;
    }
}

void C_ClientSort::sort(C_Sort &sortEngine) {
    sortEngine.sort(data);
}