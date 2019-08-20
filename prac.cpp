#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node(int el)
    {
        data=el;
        next=NULL;
    }
};
//#include"prac.h"
void mergell(node*head,node*tail,node*mid)
{
    node*temp1=head,*temp2=mid->next;
    node*nh=NULL,*nt=NULL;
    if(temp1==NULL)
    {
        nh=temp2;
        goto skip;
    }
    if(temp2==NULL)
    {
        nh=temp1;
        goto skip;
    }
    if(temp1->data<temp2->data)
    {
        nh=new node(temp1->data);
        nh->next=NULL;
        nt=nh;
        temp1=temp1->next;
    }
    else
    {
        nh=new node(temp2->data);
        nt=nh;
        temp2=temp2->next;
    }
    while(mid->next!=temp1&&tail->next!=temp2)
    {
        if(temp1->data<temp2->data)
        {
            nt->next=new node(temp1->data);
            nt=nt->next;
            nt->next=NULL;
            temp1=temp1->next;
        }
        else
        {
            nt->next=new node(temp2->data);
            nt=nt->next;
            nt->next=NULL;
            temp2=temp2->next;
        }
    }
    skip:;
    if(mid->next==temp1||temp1==NULL)
    {
        while(tail->next!=temp2)
        {
            nt->next=new node(temp2->data);
            nt=nt->next;
            temp2=temp2->next;
        }
    }
    else
    {
        while(mid->next!=temp1)
        {
            nt->next=new node(temp1->data);
            nt=nt->next;
            nt->next=NULL;
            temp1=temp1->next;
        }
    }
    node*ptrn=nh,*ptro=head;
    while(tail->next!=ptro)
    {
        ptro->data=ptrn->data;
        ptro=ptro->next;
        ptrn=ptrn->next;
    }
}
node*middle(node*head,node*tail)
{
    node*slow=head,*fast=head->next;
    while(fast!=tail&&tail->next!=fast)
    {
        slow=slow->next;
        fast=fast->next;
        fast=fast->next;
    }
    return slow;
}
void mergesort(node*head,node*tail)
{
    if(head==tail)
    {
        return;
    }
    node*mid=middle(head,tail);
    mergesort(head,mid);
    mergesort(mid->next,tail);
    mergell(head,tail,mid);

}

int main()
{
    int s,temp;
    cout<<"Enter the size ";
    cin>>s;
    cout<<"\nEnter the elements\n";
    cin>>temp;
    node*tail;
    node*head=new node(temp);
    tail=head;
    for(int i=1;i<s;i++)
    {
        cin>>temp;
        tail->next=new node(temp);
        tail=tail->next;
    }
    mergesort(head,tail);
    cout<<endl;

    node*templ=head;
    while(templ!=NULL)
    {
        cout<<templ->data<<" ";
        templ=templ->next;
    }
    return 0;
}

