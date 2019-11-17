#include<iostream>
using namespace std;

void Notes()//Just for future,no link with shell sort
{
    cout<<"//////////////NOTES/////////////////\n";
    cout<<"Modified insertion sort,like in insertion sort elements with gap 1 are \nsorted here greater gap elements are sorted,starting from n/2 and moving\n"
        <<"till 1 and using insertion sort to sort the elements at current gap\n"
        <<"Making the array gap-sorted means sorting all the subarrays with elements at gap distance";
}

void shellsort(int *arr,int n)
{
    int i,j;
    for(int gap=n/2;gap>=1;gap/=2)//changing gap
    {
        for(i=gap;i<n;i++)//sorting elements and starting from gap index like we start from 1 in insertion sort
        {
            int temp=arr[i];
            for(j=i;j>=gap;j-=gap)//sorting gap elements so j-=gap and with a j checking the j-gap element and not j element unlike insertion sort
            {
                if(arr[j-gap]>temp)
                {
                    arr[j]=arr[j-gap];//shifting the j-gap(element checked) to jth position
                }
                else
                {
                    break;
                }
            }
            arr[j]=temp;
        }
    }
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
    shellsort(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
//    Notes();
}
