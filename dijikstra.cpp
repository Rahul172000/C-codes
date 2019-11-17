#include<climits>
#include <iostream>
using namespace std;
int main()
{
  int V, E, x, y, w, min=0, newmin;
  cout<<"Vertices and edges\n";
  cin >> V >> E;
  int **arr=new int*[V];
  for(int i=0;i<V;i++)
  {
    arr[i]=new int[V];
    for(int j=0;j<V;j++)
    {arr[i][j]=0;}
  }
  cout<<"EDGES!!\n";
  for(int i=0;i<E;i++)
  {
    cout<<"Vertex 1 and vertex 2 and weight ";
    cin>>x>>y>>w;
    arr[x][y]=w;
    arr[y][x]=w;
  }
  bool*visit=new bool[V];
  for(int i=0;i<V;i++)
  {visit[i]=false;}
  int*cost=new int[V];
  cost[0]=0;
  for(int i=1;i<V;i++)
  {cost[i]=INT_MAX;}
  for(int z=1;z<V;z++)
  {
    newmin=-1;
    visit[min]=true;
    for(int i=0;i<V;i++)
    {
      if(i==min||visit[i]==true)
      {continue;}
      if(arr[min][i]!=0)
      {
        if(cost[i]>(cost[min]+arr[min][i]))
        {cost[i]=cost[min]+arr[min][i];}
      }
      if(newmin!=-1)
      {if(cost[i]<cost[newmin])
      {newmin=i;}}
      else
      {newmin=i;}
    }
    min=newmin;
  }
  cout<<endl<<"Min weights of the paths from 0 to other nodes are";
  for(int i=0;i<V;i++)
  {cout<<"\nnode:"<<i<<" weight from 0:"<<cost[i];}
  return 0;
}
