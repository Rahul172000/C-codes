#include<iostream>
using namespace std;
class edge
{
    public:
    int source,dest,weight;
};

int main()
{
    cout<<"Vertices and edges\n";
    int V,E;
    cin>>V>>E;
    edge *array_of_edges=new edge[E];
    cout<<"\nEdges\n";
    for(int i=0;i<E;i++)
    {
        cout<<"\nEnter source and destination and weight of the edge ";
        int s,d,w;
        cin>>s>>d>>w;
        array_of_edges[i].source=s;
        array_of_edges[i].dest=d;
        array_of_edges[i].weight=w;
    }
    int *weight=new int[V];
    weight[0]=0;
    for(int i=1;i<V;i++){weight[i]=INT_MAX;}
    bool flag;
    for(int i=1;i<V;i++)
    {
        flag=false;
        for(int j=0;j<E;j++)
        {
            if(weight[array_of_edges[j].dest]>(weight[array_of_edges[j].source]+array_of_edges[j].weight))
            {weight[array_of_edges[j].dest]=weight[array_of_edges[j].source]+array_of_edges[j].weight;flag=true;}
        }
        if(flag==false){break;}
    }
    cout<<"\nMinimum weights of paths of all nodes from 0 are\n";
    for(int i=0;i<V;i++)
    {cout<<endl<<"node:"<<i<<" weight from 0:"<<weight[i];}
    return 0;
}
