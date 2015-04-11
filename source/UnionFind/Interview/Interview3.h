//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_INTERVIEW3_H
#define ALGORITHMS_INTERVIEW3_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "../WeightedQuickUnion.h"

class C_Interview3 {
public:
    std::vector<unsigned int> S;
    std::vector<unsigned int> x;
    int numElements;

    C_Interview3(int N){
        numElements = N;
        S.resize(numElements);
        unsigned int n = 0;
        std::generate(S.begin(),S.end(),  [&n](){return n++; });
        x = {7,4,5,6};
    }

    void show(){
        for_each (S.begin(), S.end(), [](unsigned int &n){ std::cout << n << " "; });
        std::cout << std::endl;
    }

    void successors(){
        C_TrivialUnion uf(&S);
        for (auto x_i : x) {
            uf.connect(x_i,x_i+1);
            std::cout << S[x_i] << std::endl;
            show();
        }
    }
};


#endif //ALGORITHMS_INTERVIEW3_H
