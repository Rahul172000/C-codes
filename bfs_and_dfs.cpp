#include<iostream>
#include<queue>
using namespace std;


void dfs(bool **arr,int V,bool *visit,int cur)
{
    cout<<cur<<" ";
    visit[cur]=true;
    for(int i=0;i<V;i++)
    {
        if(i==cur){continue;}
        if(arr[i][cur]==true)
        {
            if(visit[i]==true){continue;}
            dfs(arr,V,visit,i);
        }
    }
}

void bfs(bool **arr,int V,bool *visit)
{
    queue<int> q;
    q.push(0);
    visit[0]=true;
    while(q.empty()==false)
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i=0;i<V;i++)
        {
            if(i==cur){continue;}
            if(arr[i][cur]==true)
            {
                if(visit[i]==true){continue;}
                q.push(i);
                visit[i]=true;
            }
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;
    bool **arr=new bool*[V];
    for(int i =0;i<V;i++)
    {
        arr[i]=new bool[V];
        for(int j=0;j<V;j++)
        {
            arr[i][j]=false;
        }
    }
    for(int i=0;i<E;i++)
    {
        int s,e;
        cin>>s>>e;
        arr[s][e]=true;
        arr[e][s]=true;
    }
    bool *visit=new bool[V];
    for(int i=0;i<V;i++)
    {
        visit[i]=false;
    }
    cout<<endl<<endl;
    bfs(arr,V,visit);
    for(int i=0;i<V;i++)
    {
        visit[i]=false;
    }
    cout<<endl<<endl;
    dfs(arr,V,visit,0);
    return 0;
}
