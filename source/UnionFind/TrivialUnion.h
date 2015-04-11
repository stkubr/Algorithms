//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_SLOWUNION_H
#define ALGORITHMS_SLOWUNION_H

#include <vector>
#include "Union.h"

class C_TrivialUnion : public C_Union {
protected:
    std::vector<unsigned int> *IDs_raw_ptr;
    bool ifVectorAllocated;
    void setInitialIDs();

public:
    C_TrivialUnion(unsigned int numElements);

    C_TrivialUnion(std::vector<unsigned int> * _IDs_ptr);

    virtual ~C_TrivialUnion();

    virtual bool areConnected(unsigned int inx1, unsigned int inx2);

    virtual void connect(unsigned int inx1, unsigned int inx2);

    void showIDs();

    void setIDs(std::vector<unsigned int> * _IDs_ptr);

    std::vector<unsigned int> IDs();
};


#endif //ALGORITHMS_SLOWUNION_H
