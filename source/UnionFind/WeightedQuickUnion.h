//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_WEIGHTEDQUICKUNION_H
#define ALGORITHMS_WEIGHTEDQUICKUNION_H

#include <vector>
#include "QuickUnion.h"

class C_WeightedQuickUnion: public C_QuickUnion {
protected:
    std::vector<unsigned int> treeWeights;

public:
    C_WeightedQuickUnion(unsigned int numElements);

    C_WeightedQuickUnion(std::vector<unsigned int> * _IDs_ptr);

    virtual void connect(unsigned int inx1, unsigned int inx2);
};


#endif //ALGORITHMS_WEIGHTEDQUICKUNION_H
