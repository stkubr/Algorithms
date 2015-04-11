//
// Created by stkubr on 11.04.15.
//

#include "QuickUnion.h"

C_QuickUnion::C_QuickUnion(unsigned int numElements) : C_SlowUnion(numElements) {
}

C_QuickUnion::C_QuickUnion(std::vector<unsigned int> *_IDs_ptr) : C_SlowUnion(_IDs_ptr) {
}

unsigned int C_QuickUnion::findRoot(unsigned int inx) {
    while (inx != IDs_raw_ptr->at(inx)) inx = IDs_raw_ptr->at(inx);
    return inx;
}

bool C_QuickUnion::areConnected(unsigned int inx1, unsigned int inx2) {
    return findRoot(inx1) == findRoot(inx2);
}

void C_QuickUnion::connect(unsigned int inx1, unsigned int inx2) {
    unsigned int inx_root_1 = findRoot(inx1);
    unsigned int inx_root_2 = findRoot(inx2);

    IDs_raw_ptr->at(inx_root_1) = inx_root_2;
}