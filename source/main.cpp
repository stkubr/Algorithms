#include <iostream>

#include "ClassClients/ClientUF.h"
#include "ClassClients/ClientSort.h"

using namespace std;

int main() {
    cout << "Algorithms Library presentation" << endl;

 /*   cout << "UnionFind example:" << endl;
    C_ClientUF clientUF;
    clientUF.test();
 */

    C_ClientSort clientSort(10);
    clientSort.show();
}