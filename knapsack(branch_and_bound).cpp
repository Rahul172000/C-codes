#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class item
{
    public:
    int w,v;
};

class node
{
    public:
    int bound,cost,weight;
    int level;
    vector<bool> exclude;
};

bool cmp(item a,item b)
{
    float r1=a.v/a.w;
    float r2=b.v/b.w;
    return r1>r2;
}

class compare
{
    public:
    bool operator()(node a,node b)
    {
        return a.cost<b.cost;
    }
};

class ansclass
{
public:
    vector<bool> exclude;
    int ans;
};

int calcost(item arr[],int W,int n,vector<bool> exclude)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(exclude[i]==true)
        {continue;}
        if(arr[i].w<=W)
        {
            profit+=arr[i].v;
            W-=arr[i].w;
        }
        else
        {
            profit+=W*(arr[i].v/arr[i].w);
            break;
        }
    }
    return -1*profit;
}

int calbound(item arr[],int W,int n,vector<bool> exclude)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(exclude[i]==true)
        {continue;}
        if(arr[i].w<=W)
        {
            profit+=arr[i].v;
            W-=arr[i].w;
        }
        else
        {
            break;
        }
    }
    return -1*profit;
}

ansclass BAB(item arr[],int W,int n)
{
    sort(arr,arr+n,cmp);
    priority_queue<node,vector<node>,compare> pq;
    node temp1,temp2,current;
    int ans=INT_MAX;
    vector<bool> ansexclude;
    int bound,cost;
    temp1.level=-1;
    temp1.weight=0;
    for(int i=0;i<n;i++)
    {
        temp1.exclude.push_back(false);
    }
    temp1.bound=calbound(arr,W,n,temp1.exclude);
    temp1.cost=calcost(arr,W,n,temp1.exclude);
    pq.push(temp1);
    ans=temp1.bound;
    while(pq.size()!=0)
    {
        current=pq.top();pq.pop();
        if(current.cost>ans||current.level==(n-1))
        {
            continue;
        }
        temp1.level=temp2.level=current.level+1;
        temp1.bound=current.bound;
        temp1.cost=current.cost;
        temp1.weight=current.weight+arr[temp1.level].w;
        temp1.exclude=current.exclude;
        temp2.exclude=current.exclude;
        temp2.exclude[temp2.level]=true;
        temp2.bound=calbound(arr,W,n,temp2.exclude);
        temp2.cost=calcost(arr,W,n,temp2.exclude);
        temp2.weight=current.weight;
        if(temp1.cost<=ans && temp1.weight<=W)
        {
            pq.push(temp1);
            if(temp1.bound<=ans){ans=temp1.bound;ansexclude=temp1.exclude;}
        }
        if(temp2.cost<=ans && temp2.weight<=W)
        {
            pq.push(temp2);
            if(temp2.bound<=ans){ans=temp2.bound;ansexclude=temp2.exclude;}
        }
    }
    ansclass temp;
    temp.exclude=ansexclude;
    temp.ans=ans;
    return temp;
}

int main()
{
    cout<<"\nEnter the size ";
    int n;
    cin>>n;
    item *arr=new item[n];
    cout<<"\nEnter the item's weight and value\n";
    for(int i=0;i<n;i++)
    {
        int w,v;
        cin>>w>>v;
        arr[i].w=w;
        arr[i].v=v;
    }
    cout<<"\nEnter the capacity ";
    int W;cin>>W;
    ansclass ans=BAB(arr,W,n);
    cout<<"\nAnswer is "<<-1*ans.ans;
    cout<<"\nItems to be included\n";
    for(int i=0;i<n;i++)
    {
        if(ans.exclude[i]==false)
        {
            cout<<arr[i].v<<" "<<arr[i].w<<endl;
        }
    }
    return 0;
}
