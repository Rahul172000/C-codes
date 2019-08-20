#include<iostream>
#include"test.h"
using namespace std;
int main()
{
    a obj1,obj2;
    obj1.next=&obj2;
    cout<<obj2.next<<endl<<&obj2<<endl<<obj1.next;
}
