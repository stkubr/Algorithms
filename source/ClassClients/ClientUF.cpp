//
// Created by stkubr on 11.04.15.
//

#include <iostream>
#include "ClientUF.h"
#include "../UnionFind/SlowUnion.h"

C_ClientUF::C_ClientUF() {
    numElements = 10;
    IDs =  {1,1,1,8,3,0,5,1,8,8};
}

void C_ClientUF::testUnionFind(){
    std::shared_ptr<C_Union> slowUnion(new C_SlowUnion(numElements));
    slowUnion->showIDs();
    slowUnion->connect(1,2);
    slowUnion->connect(2,8);
    slowUnion->showIDs();
    std::cout << slowUnion->areConnected(1,8) << std::endl;

    slowUnion->setIDs(&IDs);
    slowUnion->showIDs();
    std::cout << slowUnion->areConnected(0,2) << std::endl;


}