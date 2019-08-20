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
    int i=0,pivotindex=0;
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
  cout<<"THE ARRAY SIZE IS 100";
  int n=100;
  int*arr=new int[100];
  for(int i=0;i<100;i++)
  {
      int num;
      num=rand();
      arr[i]=num;
  }
  cout<<"\nTHE ARRAY is\n\n";
  for(int i=0;i<100;i++)
  {
      cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<endl<<"SORTED ARRAY IS\n";
  quicksort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
      cout<<arr[i]<<" ";
  }
}
