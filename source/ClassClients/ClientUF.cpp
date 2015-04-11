//
// Created by stkubr on 11.04.15.
//

#include <iostream>
#include "ClientUF.h"

C_ClientUF::C_ClientUF() {
    numElements = 10;
    IDs =  {0,1,2,3,4,5,6};
}

void C_ClientUF::testUnionFind(C_Union & unionFind){
    std::cout << "Show the default initial ID vector" << std::endl;
    unionFind.showIDs();
    std::cout << "connect(1,2)" << std::endl;
    unionFind.connect(1,2);
    std::cout << "connect(2,8)" << std::endl;
    unionFind.connect(2,8);
    std::cout << "Show the ID vector" << std::endl;
    unionFind.showIDs();
    std::cout << "Check if 1 and 8 are connected - " << unionFind.areConnected(1,8) << std::endl;
}

void C_ClientUF::test() {
    C_TrivialUnion trivialUnion(numElements);
    C_QuickUnion quickUnion(numElements);
    C_WeightedQuickUnion weightedQuickUnion(numElements);

    std::cout << "Connecting via C_TrivialUnion" << std::endl;
    testUnionFind(trivialUnion);
    std::cout << std::endl << "Connecting via C_QuickUnion" << std::endl;
    testUnionFind(quickUnion);
    std::cout << std::endl << "Connecting via C_WeightedQuickUnion" << std::endl;
    testUnionFind(weightedQuickUnion);
}