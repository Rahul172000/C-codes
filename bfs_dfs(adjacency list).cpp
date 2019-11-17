#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<int>*> adjlist,int V,bool *visit)
{
    queue<int> q;
    q.push(0);
    visit[0]=true;
    while(q.empty()==false)
    {
        int cur=q.front();
        q.pop();
        vector<int>temp=*(adjlist[cur]);//////coz we cannot use [] on vector pointers so used referencing operator
        cout<<cur<<" ";
        for(int i=0;i<temp.size();i++)
        {
            if(visit[temp[i]]==true){continue;}
            q.push(temp[i]);
            visit[temp[i]]=true;
        }
    }
}

void dfs(vector<vector<int>*>adjlist,int V,bool *visit,int cur)
{
    cout<<cur<<" ";
    visit[cur]=true;
    vector<int>temp=*(adjlist[cur]);
    for(int i=0;i<temp.size();i++)
    {
        if(visit[temp[i]]==true){continue;}
        dfs(adjlist,V,visit,temp[i]);
    }
}

int main()
{
    int V,E;
    cout<<"VERTICES AND EDGES\n";
    cin>>V>>E;
    vector <vector<int>*> adjlist;
    for(int i=0;i<V;i++)
    {
        vector<int>* temp=new vector<int>;
        adjlist.push_back(temp);
    }
    cout<<"\nEDGES!!!\n";
    for(int i=0;i<E;i++)
    {
        int s,e;
        cin>>s>>e;
        adjlist[s]->push_back(e);
        adjlist[e]->push_back(s);
    }
    bool *visit=new bool[V];
    for(int i=0;i<V;i++)
    {
        visit[i]=false;
    }
    cout<<endl<<endl;
    cout<<"BFS:\n";
    bfs(adjlist,V,visit);
    for(int i=0;i<V;i++)
    {
        visit[i]=false;
    }
    cout<<endl<<endl;
    cout<<"DFS:\n";
    dfs(adjlist,V,visit,0);
}
