#include<iostream>
using namespace std;

void Notes()
{
    cout<<"////////////////NOTES///////////////////////\n";
    cout<<"Radix sort use counting sort to sort all the numbers at particular digit place\n"
        <<"And then do the passes=to number of digits in maximum number\n"
        <<"and then sort the numbers on the basis of place value one by one in this order ones,tens,hundreds,...";
}

void count_sort(int*arr,int n,int exp)
{
    int countarray[10]={0,0,0,0,0,0,0,0,0,0};//size 10 coz 10 digits from 0..9
    int *output=new int[n];
    for(int i=0;i<n;i++)
    {
        countarray[(arr[i]/exp)%10]++;//making the counting sort main array
    }
    for(int i=1;i<10;i++)
    {
        countarray[i]+=countarray[i-1];//adding previous indices so that countarray[i] contains the poistion of i in output
    }
    for(int i=n-1;i>=0;i--)//started from n-1 till 0 so that those numbers already sorted are not disturbed when the current place digit is same e.g 13,12
                           //in 13,12 after first pass its 12,13 and second pass if from 0-(n-1) then 13,12 coz 13,12 both in 1 of countarray and which ever comes first is stored after the latter one in output

    {
        output[countarray[(arr[i]/exp)%10]-1]=arr[i];//inserting the arr[i] at its correct position in output
        countarray[(arr[i]/exp)%10]--;//-- done so as to update the position of rest of the elements with same digit at current place
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];//storing the contents of output back in arr so as to reflect changes
    }
}

void radix_sort(int*arr,int n)
{
    int m=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    //m contains the maximum of array so that we can find out the number of passes to be done that is number of digits in maximum number
    for(int exp=1;m/exp>0;exp*=10)
    {
        count_sort(arr,n,exp);//count sort on numbers for different digits that is digits at once place in number arr[i]/exp
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
    radix_sort(arr,n);
    cout<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Notes();
}
