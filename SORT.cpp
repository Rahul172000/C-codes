#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


void mergearrays(int*arr,int s,int mid,int e)
{
    int length=e-s+1;
    int *ptr=new int[length];
    int k=0,i=s,j=mid+1;
    while(i<=mid&&j<=e)
    {
        if(arr[i]>arr[j])
        {
            ptr[k++]=arr[j++];
        }
        else
        {
            ptr[k++]=arr[i++];
        }
    }
    while(i<=mid)
    {
        ptr[k++]=arr[i++];
    }
    while(j<=e)
    {
        ptr[k++]=arr[j++];
    }
    for(int x=s;x<=e;x++)
    {
        arr[x]=ptr[x-s];
    }
}
void mergesort(int*arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    mergearrays(arr,s,mid,e);
}

int part(int*arr,int s,int e)
{
    int pivot=arr[e];
    int i=s,pivotindex=s;
    while(i<e)
    {
        if(arr[i]<arr[e])
        {
            int temp=arr[i];
            arr[i]=arr[pivotindex];
            arr[pivotindex]=temp;
            pivotindex++;
        }
        i++;
    }
    int temp=arr[e];
    arr[e]=arr[pivotindex];
    arr[pivotindex]=temp;
    return pivotindex;
}
void quicksort(int*arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int pivot=part(arr,s,e);
    quicksort(arr,s,pivot-1);
    quicksort(arr,pivot+1,e);
}

int main()
{
  cout<<"\nEnter the size of array ";
  int n;cin>>n;
  cout<<"\nEnter the array\n";
  int *arr1=new int[n];
  int *arr2=new int[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr1[i];
      arr2[i]=arr1[i];
  }
  quicksort(arr1,0,n-1);
  cout<<"\nSorted array is\n";
  for(int i=0;i<n;i++)
  {
      cout<<arr1[i]<<" ";
  }
  cout<<endl<<endl;
  mergesort(arr2,0,n-1);
  cout<<"\nSorted array is\n";
  for(int i=0;i<n;i++)
  {
    cout<<arr2[i]<<" ";
  }
}
