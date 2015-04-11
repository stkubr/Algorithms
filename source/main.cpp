#include <iostream>

#include "ClassClients/ClientUF.h"

using namespace std;

int main() {
    cout << "Algorithms Library presentation" << endl;
    cout << "QuickFind example:" << endl;
    C_ClientUF clientUF;
    clientUF.testSlowUnionFind();
    clientUF.testQuickUnionFind();
}