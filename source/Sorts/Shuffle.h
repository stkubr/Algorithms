//
// Created by stkubr on 14.04.15.
//

#ifndef ALGORITHMS_SHUFFLE_H
#define ALGORITHMS_SHUFFLE_H


#include <vector>
#include <random>
#include <algorithm>

class C_Shuffle {
private:
    static void exchange(std::vector<double> &data, int i, int j) {
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
public:
    static void shuffle(std::vector<double> &data){
        std::random_device rd;
        std::mt19937 gen(rd());

        int numElements = data.size();

        for (int i = 0; i < numElements; ++i) {
            std::uniform_int_distribution<> uniDist(0,i);
            int inx_swap = uniDist(gen);
            exchange(data,i,inx_swap);
        }
    }
};


#endif //ALGORITHMS_SHUFFLE_H
