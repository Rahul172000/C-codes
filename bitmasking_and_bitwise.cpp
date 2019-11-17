#include<iostream>
using namespace std;

int main()
{
    /*
        1->finding number occurring odd number of times in the given array using xor operator
    */

    int arr[]={1,2,3,4,5,6,7,8,9,9,8,7,6,7,6,5,4,3,2,1,6};//answer should be 7 as it occurs 3 times
    int ans=0;
    for(int i=0;i<21;i++)
    {
        ans=ans^arr[i];
    }
    cout<<"\nunique number is "<<ans;

    /*
        2->Finding odd or even by using lsb coz if lsb is 1 then odd else even coz
           if lsb is 1 then we add 2^0 which is 1 and makes the number odd,rest all bits add even number by adding 2^n where n>0
           Lsb acquired by doing &1
    */
    int num1=12,num2=19;
    num1&1==1?cout<<endl<<num1<<":odd":cout<<endl<<num1<<":even";
    num2&1==1?cout<<endl<<num2<<":odd":cout<<endl<<num2<<":even";


    /*
        3->counting number of 1 bits in given number
    */
    int num=13/*1101*/;int count=0;
    while(num!=0)
    {
        if(num&1==1){count++;}
        num=num>>1;
    }
    cout<<endl<<"number of 1 bits="<<count;


    /*
        4->number of different bits in two given numbers using xor and then counting number of  bits
    */
    int num3=10/*1010*/,num4=4/*100*/;
    int ans4=num3^num4;
    int count4=0;
    while(ans4!=0)
    {
        if(ans4&1==1){count4++;}
        ans4=ans4>>1;
    }
    cout<<endl<<"Number of different bits="<<count4;


    /*
        5->remove the last 1 bit means turn it to zero.....ans is by (number)&(number-1) coz in number-1 all the bits after the last bit
           that is 1 are 1 and the actual bit that is to be changed is 0
    */
    int num5=10;
    cout<<"\nNumber after the operation="<<(num5&(num5-1));


    /*
        6->Swap 2 numbers using xor without any other variable
           a,b  a=a^b,,,b=a^b that is a^b^b which is a so now a=a^b and b=a and now a=a^b which is a^b^a which is a
    */
    int num6=10,num7=100;
    cout<<endl<<"num6="<<num6<<" num7="<<num7;
    num6=num6^num7;
    num7=num6^num7;
    num6=num6^num7;
    cout<<".............."<<"num6="<<num6<<" num7="<<num7;


    /*
        7->get the i th bit
    */
    int num71=10/*1010*/;
    cout<<"\n2nd index bit is="<<((num71>>2)&1);
    cout<<"\n1st index bit is="<<((num71>>1)&1);
    cout<<"\n0th index bit is="<<((num71>>0)&1);
    cout<<"\n3rd index bit is="<<((num71>>3)&1);
    cout<<"  "<<num71<<"(this implies number does not changes)";


    /*
        8->invert the i th bit using xor coz if ith bit is zor with 1 then it inverts and rest of the bits xored with 0 remains as it is
           so xor the number with 1<<i where is is the i th bit coz 1<<i means 1 at i th bit and rest 0
    */
    int num81=10/*1010*/;
    cout<<"\nafter changing the 0th bit number is="<<(num81^1);
    cout<<"\nafter changing the 1st bit number is="<<(num81^(1<<1));
    cout<<"\nafter changing the 2nd bit number is="<<(num81^(1<<2));
    cout<<"\nafter changing the 3rd bit number is="<<(num81^(1<<3));
}
