#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

class treeNode
{
    public:
    char character;
    int freq;
    treeNode*left,*right;
    treeNode(char c,int f)
    {
        left=right=NULL;
        character=c;
        freq=f;
    }
};

class compare
{
public:
    bool operator()(treeNode* a,treeNode* b)
    {
        return a->freq>b->freq;
    }

};

void printcodes(treeNode*root,string ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->character!='\0')
    {
        cout<<root->character<<":"<<ans<<endl;
    }
    printcodes(root->left,ans+'0');
    printcodes(root->right,ans+'1');
}

int main()
{
    priority_queue<treeNode*,vector<treeNode*>,compare> mq;
    cout<<"Enter the number of characters:";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;int f;
        cout<<"\nCharacter and frequency:";
        cin>>c>>f;
        treeNode *temp=new treeNode(c,f);
        mq.push(temp);
    }
    while(mq.size()>1)
    {
        treeNode *node1,*node2;
        node1=mq.top();mq.pop();
        node2=mq.top();mq.pop();
        treeNode *newnode=new treeNode('\0',node1->freq+node2->freq);
        newnode->left=node1;
        newnode->right=node2;
        mq.push(newnode);
    }
    treeNode *root;
    root=mq.top();
    cout<<endl<<endl;
    printcodes(root,"");
}
