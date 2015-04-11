//
// Created by stkubr on 11.04.15.
//

#include <iostream>
#include "ClientUF.h"
#include "../UnionFind/SlowUnion.h"
#include "../UnionFind/QuickUnion.h"

C_ClientUF::C_ClientUF() {
    numElements = 10;
    IDs =  {1,1,1,8,3,0,5,1,8,8};
}

void C_ClientUF::testSlowUnionFind(){
    std::shared_ptr<C_Union> slowUnion(new C_SlowUnion(numElements));
    std::cout << "Show the default initial ID vector" << std::endl;
    slowUnion->showIDs();
    std::cout << "connect(1,2)" << std::endl;
    slowUnion->connect(1,2);
    std::cout << "connect(2,8)" << std::endl;
    slowUnion->connect(2,8);
    std::cout << "Show the ID vector" << std::endl;
    slowUnion->showIDs();
    std::cout << "Check if 1 and 8 are connected - " << slowUnion->areConnected(1,8) << std::endl;

    std::cout << "Replace the ID vector with externaly provided" << std::endl;
    slowUnion->setIDs(&IDs);
    slowUnion->showIDs();
    std::cout << "Check if 0 and 2 are connected - " << slowUnion->areConnected(0,2) << std::endl;
    std::cout << std::endl;
}

void C_ClientUF::testQuickUnionFind() {
    std::shared_ptr<C_Union> quickUnion(new C_QuickUnion(numElements));
    std::cout << "Show the default initial ID vector" << std::endl;
    quickUnion->showIDs();
    std::cout << "connect(1,2)" << std::endl;
    quickUnion->connect(1,2);
    std::cout << "connect(2,8)" << std::endl;
    quickUnion->connect(2,8);
    std::cout << "Show the ID vector" << std::endl;
    quickUnion->showIDs();
    std::cout << "Check if 1 and 8 are connected - " << quickUnion->areConnected(1,8) << std::endl;

    std::cout << "Replace the ID vector with externaly provided" << std::endl;
    quickUnion->setIDs(&IDs);
    quickUnion->showIDs();
    std::cout << "Check if 0 and 5 are connected - " << quickUnion->areConnected(0,5) << std::endl;
}