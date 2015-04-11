//
// Created by stkubr on 11.04.15.
//

#include <iostream>
#include "SlowUnion.h"

C_SlowUnion::C_SlowUnion(unsigned int numElements) {
    IDs_raw_ptr = new std::vector<unsigned int>(numElements);
    ifVectorAllocated = true;
    IDs_raw_ptr->resize(numElements);
    setInitialIDs();
}

C_SlowUnion::C_SlowUnion(std::vector<unsigned int> * _IDs_ptr) {
    if(_IDs_ptr){
        IDs_raw_ptr = _IDs_ptr;
        ifVectorAllocated = false;
    } else {
        std::cerr << "NULL pointer detected." << std::endl;
    }
}

C_SlowUnion::~C_SlowUnion() {
    if (ifVectorAllocated) delete [] IDs_raw_ptr;
}

void C_SlowUnion::setInitialIDs() {
    if (IDs_raw_ptr->size()>0)
        for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
            IDs_raw_ptr->at(i)=i;
        }
}

bool C_SlowUnion::areConnected(unsigned int inx1, unsigned int inx2) {
    return IDs_raw_ptr->at(inx1) == IDs_raw_ptr->at(inx2);
}

void C_SlowUnion::connect(unsigned int inx1, unsigned int inx2) {
    unsigned int inx1_id = IDs_raw_ptr->at(inx1);
    unsigned int inx2_id = IDs_raw_ptr->at(inx2);

    for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
        if (IDs_raw_ptr->at(i)==inx1_id) IDs_raw_ptr->at(i) = inx2_id;
    }
}

void C_SlowUnion::showIDs() {
    if (IDs_raw_ptr->size()>0)
        for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
            std::cout << IDs_raw_ptr->at(i) << std::endl;
        }
    std::cout << std::endl;
}

void C_SlowUnion::setIDs(std::vector<unsigned int> * _IDs_ptr) {
    if(IDs_raw_ptr) delete [] IDs_raw_ptr; // delete the previous IDs if were allocated
    IDs_raw_ptr = _IDs_ptr;
}

std::vector<unsigned int> C_SlowUnion::IDs() {
    return (*IDs_raw_ptr);
}