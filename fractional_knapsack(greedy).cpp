#include<iostream>
#include<algorithm>
using namespace std;

class item
{
public:
    int weight,value;
};

bool comp(item a,item b)
{
    float r1=a.value/a.weight;
    float r2=b.value/b.weight;
    return r1>r2;
}

int main()
{
    cout<<"\nEnter the number of items ";
    int n;cin>>n;
    item *arr=new item[n];
    cout<<"\nEnter the item's weight and their values\n";
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i].weight=a;
        arr[i].value=b;
    }
    sort(arr,arr+n,comp);
    cout<<"\nEnter the maximum weight ";
    int maxweight;cin>>maxweight;
    float total_value=0;
    int total_weight=0;
    for(int i=0;i<n;i++)
    {
        if((arr[i].weight+total_weight)<maxweight)
        {
            total_value+=arr[i].value;
            total_weight+=arr[i].weight;
        }
        else
        {
            total_value+=arr[i].value/arr[i].weight*(maxweight-total_weight);
            break;
        }
    }
    cout<<"\n\nThe final value in knapsack is:"<<total_value;
    return 0;
}
