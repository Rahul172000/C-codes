// A naive recursive implementation of
// optimal binary search tree problem
#include <bits/stdc++.h>
using namespace std;
int keys[] = {10,12,16,21};
class item
{
    public:
    stack<int> s;
    int cost;
    item()
    {
        cost=0;
    }
};

class treenode
{
    public:
        int value;treenode *l,*r;
};
// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j);

// A recursive function to calculate
// cost of optimal binary search tree
item optCost(int freq[], int i, int j)
{
    // Base cases
    if (j < i)  // no elements in this subarray
        {
            item i;
            return i;
        }
    if (j == i) // one element in this subarray
        {
            item temp;
            temp.cost=freq[i];
            temp.s.push(keys[i]);
        }

    // Get sum of freq[i], freq[i+1], ... freq[j]
    int fsum = sum(freq, i, j);
    int root=-1;
    // Initialize minimum value
    item ans;
    ans.cost=INT_MAX;

    // One by one consider all elements
    // as root and recursively find cost
    // of the BST, compare the cost with
    // min and update min if needed
    for (int r = i; r <= j; r++)
    {
        item templ = optCost(freq, i, r - 1);
        item tempr=optCost(freq, r + 1, j);
        item temp;
        temp.cost=templ.cost+tempr.cost;
        temp.s=tempr.s;
        stack<int> test;
        while(templ.s.size()!=0)
        {
            test.push(templ.s.top());
            templ.s.pop();
        }
        while(test.size()!=0)
        {
            temp.s.push(test.top());
            test.pop();
        }
        if (temp.cost < ans.cost)
            {ans.cost = temp.cost;ans.s=temp.s;root=r;}
    }
    ans.s.push(keys[root]);
    ans.cost+=fsum;
    // Return minimum value
    return ans;
}

// The main function that calculates
// minimum cost of a Binary Search Tree.
// It mainly uses optCost() to find
// the optimal cost.
/*int optimalSearchTree(int keys[],
                      int freq[], int n)
{
    // Here array keys[] is assumed to be
    // sorted in increasing order. If keys[]
    // is not sorted, then add code to sort
    // keys, and rearrange freq[] accordingly.
    return optCost(freq, 0, n - 1);
}*/

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    s += freq[k];
    return s;
}

treenode* make(treenode*root,int d)
{
    if(root==NULL)
    {
        treenode*temp=new treenode;
        temp->value=d;temp->l=NULL;temp->r=NULL;
        return temp;
    }
    if(root->value>d){root->l=make(root->l,d);}
    else{root->r=make(root->r,d);}
    return root;

}

void printtree(treenode*root)
{
    if(root==NULL){return;}
    cout<<root->value<<endl;
    printtree(root->l);
    printtree(root->r);
}
// Driver Code
int main()
{

    int freq[] = {4,2,6,3};
    int n = sizeof(keys) / sizeof(keys[0]);
    item ans=optCost(freq,0,n-1);
    cout << "Cost of Optimal BST is "
         << ans.cost<<endl;
         while(ans.s.size()!=0)
         {
             cout<<ans.s.top()<<endl;ans.s.pop();
         }
    treenode*root=new treenode;
    root->value=ans.s.top();
    ans.s.pop();
    while(ans.s.size()!=0){root=make(root,ans.s.top());ans.s.pop();}
    printtree(root);
    return 0;
}
