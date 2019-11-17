#include<iostream>
using namespace std;

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
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            ans=i;
        }
    }
    if(ans==-1){cout<<"\nNOT PRESENT";}
    else{cout<<"\nPRESESNT AT "<<ans;}
}
