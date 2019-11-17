#include<iostream>
using namespace std;

int graph[5][5]={0,10,15,20,20,
                5,0,9,10,10,
                6,13,0,12,12,
                8,8,9,0,1,
                7,6,5,4,0};

int base_case=(1<<5)-1;


int tsp(int current,int mask,int arr[32][5])
{
    if(mask==base_case){return graph[current][0];}
    if(arr[mask][current]!=-1)
    {
        cout<<"\nUsed "<<mask<<" "<<current;
        return arr[mask][current];
    }
    int ans=INT_MAX;
    for(int i=0;i<5;i++)
    {
        int temp=mask;
        int new_mask=mask|(1<<i);
        if(((temp>>i)&1)==0)
        {
            int temp=graph[current][i]+tsp(i,new_mask,arr);
            if(temp<ans){ans=temp;}
        }
    }
    arr[mask][current]=ans;
    return ans;
}



int main()
{
    int test[32][5];
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<5;j++){test[i][j]=-1;}
    }
    cout<<"\n\nAnswer is:"<<tsp(0,1,test);
    return 0;
}
