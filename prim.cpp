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
  cout<<"Edges!!\n";
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
  int *weight=new int[V];
  int *parent=new int[V];
  weight[0]=0;
  parent[0]=-1;
  for(int i=1;i<V;i++)
  {
    parent[i]=-1;
    weight[i]=INT_MAX;
  }
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
        if(visit[i]==true)
        {continue;}
        if(weight[i]>arr[min][i])
        {
          weight[i]=arr[min][i];
          parent[i]=min;
        }
      }
      if(newmin!=-1)
      {if(weight[newmin]>weight[i])
      {newmin=i;}}
      else
      {newmin=i;}
    }
    min=newmin;
  }
  cout<<endl<<"MST edges are\n";
  for(int i=1;i<V;i++)
  {
    if(i<parent[i])
    {cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;}
    else
    {cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;}
  }
  return 0;
}
