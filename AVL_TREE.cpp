#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
class treenode
{
public:
    int data,lh,rh;
    treenode*left,*right;
    treenode(int d)
    {
        data=d;
        lh=rh=0;
        left=right=NULL;
    }
};
class avl
{
public:
    bool res;
    int h;
    treenode*ptr;
    avl()
    {
        ptr=NULL;
        res=true;
        h=1;
    }
};
class avltree
{
    private:
    treenode*root;
    treenode* p_add(treenode*root,int d)
    {
        if(root==NULL)
        {
            root=new treenode(d);
            return root;
        }
        if(root->data>d)
        {
            root->left=p_add(root->left,d);
        }
        else
        {
            root->right=p_add(root->right,d);
        }
        return root;
    }
    avl bf(treenode*root,int d)
    {
        if(root->data==d)
        {
            avl temp;
            return temp;
        }
        if(root->data<d)
        {
            avl temp=bf(root->right,d);
            root->rh=temp.h;
            if(temp.ptr!=NULL)
            {
                root->right=temp.ptr;
                temp.ptr=NULL;
            }
            int check=root->lh-root->rh;
            temp.res=check==-1||check==0||check==1;
            if(temp.res==false)
            {
                treenode*a=root;
                if(check>0)
                {
                    treenode*b=a->left;
                    if((b->lh-b->rh)>0)
                    {
                        temp.ptr=ll(a,b);
                    }
                    else
                    {
                        treenode*c=b->right;
                        temp.ptr=lr(a,b,c);
                    }
                }
                else
                {
                    treenode*b=a->right;
                    if((b->lh-b->rh)<0)
                    {
                        temp.ptr=rr(a,b);
                    }
                    else
                    {
                        treenode*c=b->left;
                        temp.ptr=rl(a,b,c);
                    }
                }
                root=temp.ptr;
            }
            temp.res=true;
            temp.h=max(root->lh,root->rh)+1;
            return temp;
        }
        else
        {
            avl temp=bf(root->left,d);
            root->lh=temp.h;
            if(temp.ptr!=NULL)
            {
                root->left=temp.ptr;
                temp.ptr=NULL;
            }
            int check=root->lh-root->rh;
            temp.res=check==-1||check==0||check==1;
            if(temp.res==false)
            {
                treenode*a=root;
                if(check>0)
                {
                    treenode*b=a->left;
                    if((b->lh-b->rh)>0)
                    {
                        temp.ptr=ll(a,b);
                    }
                    else
                    {
                        treenode*c=b->right;
                        temp.ptr=lr(a,b,c);
                    }
                }
                else
                {
                    treenode*b=a->right;
                    if((b->lh-b->rh)<0)
                    {
                        temp.ptr=rr(a,b);
                    }
                    else
                    {
                        treenode*c=b->left;
                        temp.ptr=rl(a,b,c);
                    }
                }
                root=temp.ptr;
            }
            temp.res=true;
            temp.h=max(root->lh,root->rh)+1;
            return temp;
        }
    }
    treenode*ll(treenode*a,treenode*b)
    {
        treenode*temp=b->right;
        b->right=a;
        a->left=temp;
        a->lh=b->rh;
        b->rh=max(a->lh,a->rh)+1;
        return b;
    }
    treenode*rr(treenode*a,treenode*b)
    {
        treenode*temp=b->left;
        b->left=a;
        a->right=temp;
        a->rh=b->lh;
        b->lh=max(a->lh,a->rh)+1;
        return b;
    }
    treenode*lr(treenode*a,treenode*b,treenode*c)
    {
        b=rr(b,c);
        return ll(a,b);
    }
    treenode*rl(treenode*a,treenode*b,treenode*c)
    {
        b=ll(b,c);
        return rr(a,b);
    }
    public:
        avltree()
        {
            root=NULL;
        }
        void add(int d)
        {
            root=p_add(root,d);
            avl temp=bf(root,d);
            if(temp.ptr!=NULL)
            {
                root=temp.ptr;
                temp.ptr=NULL;
            }
        }
        void level_wise_print()
        {
            if(root==NULL)
            {
                return;
            }
            queue<treenode*>q;
            treenode*ptr;
            q.push(root);
            int i=1,j=1,k=0;
            while(q.empty()==0)
            {
                ptr=q.front();
                q.pop();
                if(i>j)
                {
                    i=1;
                    j=k;
                    k=0;
                    cout<<endl;
                }
                cout<<ptr->data<<" ";
                if(ptr->left!=NULL)
                {
                    k++;q.push(ptr->left);
                }
                if(ptr->right!=NULL)
                {
                    k++;q.push(ptr->right);
                }
                i++;
            }
        }
};
int main()
{
    avltree avt;
    int choice;
    do{
        cout<<"\n1.To add\n2.To print\n-1.To exit\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"\nEnter data ";int temp;cin>>temp;
            avt.add(temp);
        }
        else if(choice==2)
        {
            cout<<endl;
            avt.level_wise_print();
        }
        else if(choice!=-1)
        {
            cout<<"\nEnter valid option";
        }
    }while(choice!=-1);
}
