//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_CLIENTUF_H
#define ALGORITHMS_CLIENTUF_H

#include <vector>
#include <memory>

class C_ClientUF {
    unsigned int numElements;
    std::vector<unsigned int> IDs;
public:
    C_ClientUF();

    void testSlowUnionFind();
    void testQuickUnionFind();
};


#endif //ALGORITHMS_CLIENTUF_H
