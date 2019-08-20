#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
node* ms(node*head1,node*head2,node*tail1,node*tail2)
{
    if(head1==NULL||head2==NULL)
    {
        if(head1==NULL)
        {
            return head2;
        }
        else
        {
            return head1;
        }
    }
    node*fh,*ft;
    node*temp1=head1,*temp2=head2;
    if(temp1->data<temp2->data)
    {
        fh=temp1;
        ft=temp1;
        temp1=temp1->next;
    }
    else
    {
        fh=temp2;
        ft=temp2;
        temp2=temp2->next;
    }
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            ft->next=temp1;
            ft=temp1;
            temp1=temp1->next;
        }
        else
        {
            ft->next=temp2;
            ft=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1==NULL)
    {
        ft->next=temp2;
        return fh;
    }
    else
    {
        ft->next=temp1;
        return fh;
    }
}
node*middle(node*head,node*tail)
{
    if(head==NULL)
    {
        return NULL;
    }
    node*slow=head,*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* mergesort(node*head,node*tail)
{
    if(head==tail||tail->next==head)
    {
        if(head==tail)
        {
            return head;
        }
        else
        {
            return tail;
        }
    }
    node*mid=middle(head,tail);
    node*nhead=mid->next;
    mid->next=NULL;
    head=mergesort(head,mid);
    nhead=mergesort(nhead,tail);
    head=ms(head,nhead,mid,tail);   ///////////////////////OVER HERE NO NEED TO PASS TAIL1 AND TAIL2 AS TAIL IS ONLY USED TO REACH BASE CASE AND AFTER THAT TAIL IS NOT USED
    return head;                    ///////////////////////ANYWHERE HENCE EVEN THOUGH TAIL CHANGES WHILE SORTING,THE CHANGES IN TAIL ARE NOT SAVED AND ONLY CHANGES IN HEAD ARE
}                                   ///////////////////////SAVED.......
int main()
{
    int temp;
    node*head=NULL,*tail;
    cout<<"Enter the elements\n";
    while(temp!=-1)
    {
        cin>>temp;
        if(temp==-1)
        {
            break;
        }
        if(head==NULL)
        {
            head=new node(temp);
            tail=head;
        }
        else
        {
            tail->next=new node(temp);
            tail=tail->next;
        }
    }
    head=mergesort(head,tail);
    node*t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
