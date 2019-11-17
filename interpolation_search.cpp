#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int inter_search(int *arr,int h,int l,int x)
{
    while(h>=l)
    {
        int mid=l+((h-l)*(x-arr[l]))/(arr[h]-arr[l]);
        if(arr[mid]>arr[h]||arr[mid]<arr[l])
        {
            return -1;
        }
        if(arr[mid]>x)
        {
            h=mid-1;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    sort(arr,arr+n);
    cout<<"\nAfter sorting array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ans=inter_search(arr,n-1,0,x);
    if(ans!=-1){cout<<"PRESENT AT "<<ans;}
    else{cout<<"NOT PRESENT";}
}
