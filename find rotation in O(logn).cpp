#include<bits/stdc++.h>
using namespace std;

int fun(int*arr,int s,int e)
{
    int mid=(s+e)/2;
    if(arr[mid]>arr[s]&&arr[mid]<arr[e])
    {
        return 0;
    }
    if(arr[mid]<=arr[s]&&arr[mid]<=arr[e])
    {
        if(arr[mid]<arr[mid-1])
        {
            return mid;
        }
        return fun(arr,s,mid-1);
    }
    if(arr[mid]>=arr[s]&&arr[mid]>=arr[e])
    {
        if(arr[mid]>arr[mid+1])
        {
            return mid+1;
        }
        return fun(arr,s+1,e);
    }
}
/*   mid
1 2 3 4 5
5 1 2 3 4
4 5 1 2 3
3 4 5 1 2
2 3 4 5 1
1 2 3 4 5*/
int func(int*arr,int s)
{
    for(int i=1;i<s;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int s;
    cin>>s;
    int*ptr=new int[s];
    for(int i=0;i<s;i++)
    {
        cin>>ptr[i];
    }
    std::clock_t start;
    double duration;
    start = std::clock();
    int n=fun(ptr,0,s-1);
    cout<<endl<<"THE ANSWER IS "<<n;
    cout<<endl;
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "Time Taken : " << duration << '\n';


    std::clock_t start1;
    double duration1;
    start1 = std::clock();
    cout<<endl<<endl<<func(ptr,s);
    cout<<endl;
    duration1 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;

    std::cout << "Time Taken : " << duration1 << '\n';
}
