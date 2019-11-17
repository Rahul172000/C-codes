#include<iostream>
using namespace std;

void counting_sort(int*arr,int n)
{
    int m=arr[0];
    for(int i=1;i<n;i++)
    {
        if(m<arr[i])
        {
            m=arr[i];
        }
    }
    int freq[m+1]={0};
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        freq[i]+=freq[i-1];
    }//now at ith index we have correct position of i in output array
    int*output=new int[n];
    for(int i=0;i<n;i++)
    {
        output[freq[arr[i]]-1]=arr[i];
        freq[arr[i]]--;//for same elements so that to update their position
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

int main()
{
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    counting_sort(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
