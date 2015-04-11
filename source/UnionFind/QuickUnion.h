//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_QUICKUNION_H
#define ALGORITHMS_QUICKUNION_H

#include <vector>
#include "SlowUnion.h"

class C_QuickUnion: public C_SlowUnion{
private:
    unsigned int findRoot(unsigned int inx);

public:
    C_QuickUnion(unsigned int numElements);

    C_QuickUnion(std::vector<unsigned int> * _IDs_ptr);

    virtual bool areConnected(unsigned int inx1, unsigned int inx2);

    virtual void connect(unsigned int inx1, unsigned int inx2);
};


#endif //ALGORITHMS_QUICKUNION_H
