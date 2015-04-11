//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_UNION_H
#define ALGORITHMS_UNION_H

#include <vector>
#include <memory>

class C_Union {
public:
    virtual bool areConnected(unsigned int inx1, unsigned int inx2)=0;

    virtual void connect(unsigned int inx1, unsigned int inx2)=0;

    virtual void showIDs()=0;

    virtual void setIDs(std::vector<unsigned int> * IDs_ptr)=0;

    virtual std::vector<unsigned int> IDs()=0;

    virtual ~C_Union() {};
};


#endif //ALGORITHMS_UNION_H
