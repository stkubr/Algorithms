//
// Created by stkubr on 11.04.15.
//

#ifndef ALGORITHMS_CLIENTUF_H
#define ALGORITHMS_CLIENTUF_H

#include <vector>
#include <memory>
#include "../UnionFind/TrivialUnion.h"
#include "../UnionFind/QuickUnion.h"
#include "../UnionFind/WeightedQuickUnion.h"

class C_ClientUF {
    unsigned int numElements;
    std::vector<unsigned int> IDs;
    void testUnionFind(C_Union & unionFind);
public:
    C_ClientUF();

    void test();
};


#endif //ALGORITHMS_CLIENTUF_H
