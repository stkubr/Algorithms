//
// Created by stkubr on 11.04.15.
//

#include "WeightedQuickUnion.h"

C_WeightedQuickUnion::C_WeightedQuickUnion(unsigned int numElements): C_QuickUnion(numElements) {
    treeWeights.resize(numElements,1);
}

C_WeightedQuickUnion::C_WeightedQuickUnion(std::vector<unsigned int> *_IDs_ptr): C_QuickUnion(_IDs_ptr) {
    if (_IDs_ptr) {
        treeWeights.resize(_IDs_ptr->size(),1);
    }
}

void C_WeightedQuickUnion::connect(unsigned int inx1, unsigned int inx2) {
    unsigned int inx_root_1 = findRoot(inx1);
    unsigned int inx_root_2 = findRoot(inx2);

    if (inx_root_1 == inx_root_2) return;

    if (treeWeights[inx_root_1] > treeWeights[inx_root_2]){
        IDs_raw_ptr->at(inx_root_2) = inx_root_1;
        treeWeights[inx_root_1] += treeWeights[inx_root_2];
    } else {
        IDs_raw_ptr->at(inx_root_1) = inx_root_2;
        treeWeights[inx_root_2] += treeWeights[inx_root_1];
    }
}