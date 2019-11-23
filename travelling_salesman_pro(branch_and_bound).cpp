#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class ansclass
{
public:
    int ans;
    vector<int>path;
};

class node
{
public:
    int value,cost,mask;
    int matrix[5][5];
    vector<int>path;
};

class compare
{
public:
    bool operator()(node a,node b)
    {
        return a.cost>b.cost;
    }
};

void copy_matrix(int source[5][5],int dest[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dest[i][j]=source[i][j];
        }
    }
}

void printmat(int mat[5][5])
{
    cout<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int reduce_matrix(int parent_mat[5][5],int child_mat[5][5],int parent,int child)
{
    copy_matrix(parent_mat,child_mat);
    child_mat[child][0]=INT_MAX;
    for(int i=0;i<5;i++)
    {
        child_mat[parent][i]=INT_MAX;
        child_mat[i][child]=INT_MAX;
    }
    int cost=0;
    for(int i=0;i<5;i++)
    {
        int temp=child_mat[i][0];
        for(int j=1;j<5;j++)
        {
            if(child_mat[i][j]<temp)
            {
                temp=child_mat[i][j];
            }
        }
        if(temp==INT_MAX){continue;}
        cost+=temp;
        for(int j=0;j<5;j++)
        {
            if(child_mat[i][j]!=INT_MAX)
            {child_mat[i][j]-=temp;}
        }

    }
    for(int i=0;i<5;i++)
    {
        int temp=child_mat[0][i];
        for(int j=1;j<5;j++)
        {
            if(child_mat[j][i]<temp)
            {
                temp=child_mat[j][i];
            }
        }
        if(temp==INT_MAX){continue;}
        cost+=temp;
        for(int j=0;j<5;j++)
        {
            if(child_mat[j][i]!=INT_MAX)
            {child_mat[j][i]-=temp;}
        }
    }
    return cost;
}

ansclass BAB(int matrix[5][5],int initial_cost)
{
    int ans=INT_MAX;
    vector<int>anspath;
    priority_queue<node,vector<node>,compare> pq;
    node temp;
    temp.value=0;
    temp.cost=initial_cost;
    temp.mask=1;
    copy_matrix(matrix,temp.matrix);
    temp.path.push_back(0);
    pq.push(temp);
    while(pq.size()!=0)
    {
        node current=pq.top();
        pq.pop();
        if(current.mask==31)
        {
            if(current.cost<ans)
            {
                ans=current.cost;
                anspath=current.path;
            }
            continue;
        }
        if(current.cost>ans)
        {
            continue;
        }
        for(int i=0;i<5;i++)
        {
            int temp_mask=current.mask;
            if((temp_mask>>i)&1==1)
            {
                continue;
            }
            temp.value=i;
            temp.path=current.path;
            temp.path.push_back(i);
            temp.mask=(current.mask)|(1<<i);
            temp.cost=reduce_matrix(current.matrix,temp.matrix,current.value,temp.value)+current.cost+current.matrix[current.value][temp.value];
           // if(i==2&&current.value==0){printmat(temp.matrix);}
          //  cout<<temp.value<<" "<<temp.cost<<" "<<temp.value<<" "<<current.value<<endl;
            pq.push(temp);
        }
    }
    ansclass finalans;
    finalans.ans=ans;
    finalans.path=anspath;
    return finalans;
}

int main()
{
    cout<<"\nStarting.....";
    int matrix[5][5]=
    {
        {INT_MAX,20,30,10,11},
        {15,INT_MAX,16,4,2},
        {3,5,INT_MAX,2,4},
        {19,6,18,INT_MAX,3},
        {16,4,7,16,INT_MAX}
    };
    int arr[5][5]=
    {
        {INT_MAX,20,30,10,11},
        {15,INT_MAX,16,4,2},
        {3,5,INT_MAX,2,4},
        {19,6,18,INT_MAX,3},
        {16,4,7,16,INT_MAX}
    };
    //reducing matrix
    int cost=0;
    for(int i=0;i<5;i++)
    {
        int temp=arr[i][0];
        for(int j=1;j<5;j++)
        {
            if(arr[i][j]<temp)
            {
                temp=arr[i][j];
            }
        }
        cost+=temp;
        for(int j=0;j<5;j++)
        {
            arr[i][j]-=temp;
        }
    }

    for(int i=0;i<5;i++)
    {
        int temp=arr[0][i];
        for(int j=1;j<5;j++)
        {
            if(arr[j][i]<temp)
            {
                temp=arr[j][i];
            }
        }
        cost+=temp;
        for(int j=0;j<5;j++)
        {
            arr[j][i]-=temp;
        }
    }
    ansclass temp=BAB(arr,cost);
    cout<<"Total cost is "<<temp.ans;
    cout<<"\nPath\n";
    for(int i=0;i<temp.path.size();i++)
    {
        cout<<temp.path[i]<<"->";
    }
    cout<<"0";
}
