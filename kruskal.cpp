#include <iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2)
{return e1.weight<e2.weight;}
int findParent(int v,int*parent){
    if(parent[v]==v)
    {return v;}
    return findParent(parent[v],parent);
}
void kruskals(Edge *input,int V,int E){
    sort(input,input+E,compare);
    Edge *output= new Edge[V-1];
    int *parent=new int[V];
    for(int i=0;i<V;i++)
    {parent[i]=i;}
    int count=0;
    int i=0;
    while(count != V-1){
        Edge currentEdge=input[i];
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent != destParent){
            output[count]=currentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    for(int i=0;i<V-1;i++){
        if(output[i].source <output[i].dest)
        {cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;}
        else
        {cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;}
    }
}
int main()
{
  int V, E, tempX, tempY;
  cout<<"Vertices and edges\n";
  cin >> V >> E;
    Edge *input=new Edge[E];
    cout<<"\nEdges!!!";
    for(int i=0;i<E;i++){
        int s,d,w;
        cout<<"\nVertex 1 and vertex 2 and weight of the edge ";
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    cout<<"\nMST edges are\n";
    kruskals(input,V, E);
}

