#include<iostream>
using namespace std;

void insertionsort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];int j;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
    cout<<"\nSorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selectionsort(int *arr,int n)
{
    for(int i=0;i<(n-1);i++)
    {
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[pos])
            {
                pos=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
    cout<<"\nSorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    cout<<"\nEnter the number of elements ";
    int n;cin>>n;
    cout<<"\nEnter the elements\n";
    int *arr1=new int[n];
    int *arr2=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }
    insertionsort(arr1,n);
    cout<<endl<<endl;
    selectionsort(arr2,n);
    return 0;
}
