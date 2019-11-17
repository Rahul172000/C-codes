#include<iostream>
#include<algorithm>
using namespace std;

int bs(int *arr,int l,int h,int x)
{
    if(l>h){return -1;}
    int mid=(l+h)/2;
    if(arr[mid]==x){return mid;}
    else if(arr[mid]>x){return bs(arr,l,mid-1,x);}
    else{return bs(arr,mid+1,h,x);}
}

int main()
{
    cout<<"\nEnter the size of the array ";int n;cin>>n;
    int *arr=new int[n];
    cout<<"\nEnter the array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter the element to be searched ";int x;cin>>x;
    sort(arr,arr+n);
    cout<<"\nAfter sorting array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int ans=bs(arr,0,n-1,x);
    if(ans==-1){cout<<"\nNOT PRESENT";}
    else{cout<<"\nPRESENT AT "<<ans;}
}
