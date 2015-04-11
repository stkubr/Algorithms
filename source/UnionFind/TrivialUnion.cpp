//
// Created by stkubr on 11.04.15.
//

#include <iostream>
#include "TrivialUnion.h"

C_TrivialUnion::C_TrivialUnion(unsigned int numElements) {
    IDs_raw_ptr = new std::vector<unsigned int>(numElements);
    ifVectorAllocated = true;
    IDs_raw_ptr->resize(numElements);
    setInitialIDs();
}

C_TrivialUnion::C_TrivialUnion(std::vector<unsigned int> * _IDs_ptr) {
    if(_IDs_ptr){
        IDs_raw_ptr = _IDs_ptr;
        ifVectorAllocated = false;
    } else {
        std::cerr << "NULL pointer detected." << std::endl;
    }
}

C_TrivialUnion::~C_TrivialUnion() {
    if (ifVectorAllocated) delete IDs_raw_ptr;
}

void C_TrivialUnion::setInitialIDs() {
    if (IDs_raw_ptr->size()>0)
        for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
            IDs_raw_ptr->at(i)=i;
        }
}

bool C_TrivialUnion::areConnected(unsigned int inx1, unsigned int inx2) {
    return IDs_raw_ptr->at(inx1) == IDs_raw_ptr->at(inx2);
}

void C_TrivialUnion::connect(unsigned int inx1, unsigned int inx2) {
    unsigned int inx1_id = IDs_raw_ptr->at(inx1);
    unsigned int inx2_id = IDs_raw_ptr->at(inx2);

    for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
        if (IDs_raw_ptr->at(i)==inx1_id) IDs_raw_ptr->at(i) = inx2_id;
    }
}

void C_TrivialUnion::showIDs() {
    if (IDs_raw_ptr->size()>0)
        for (unsigned int i = 0; i < IDs_raw_ptr->size(); ++i) {
            std::cout << IDs_raw_ptr->at(i) << " ";
        }
    std::cout << std::endl;
}

void C_TrivialUnion::setIDs(std::vector<unsigned int> * _IDs_ptr) {
    if(IDs_raw_ptr) { delete IDs_raw_ptr;  ifVectorAllocated = false;} // delete the previous IDs if were allocated
    IDs_raw_ptr = _IDs_ptr;
}

std::vector<unsigned int> C_TrivialUnion::IDs() {
    return (*IDs_raw_ptr);
}