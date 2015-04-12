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
    std::generate(data.begin(),data.end(), [](){return uniformDistribution(generator);});
}

void C_ClientSort::show() {
    for (auto x: data){
        std::setprecision(16);
        std::cout << x << std::endl;
    }
}
