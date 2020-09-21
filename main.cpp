#include <iostream>
#include "Set.h"
using namespace std;
int main() {
    cout<<"test '+' :"<<endl;
    Set<int>s1,s2;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s1=s1+s2;
    s1.print();
    return 0;
}
