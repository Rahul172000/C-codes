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
node*qs(node*head,node*tail)
{
    node*pivot=head,*i=head;
    int temp;
    for(;i!=tail;i=i->next)
    {
        if(i->data<tail->data)
        {
            temp=i->data;
            i->data=pivot->data;
            pivot->data=temp;
            pivot=pivot->next;
        }
    }
    temp=tail->data;
    tail->data=pivot->data;
    pivot->data=temp;
    return pivot;
}
void quicksort(node*head,node*tail)
{
    if(head==tail||tail->next==head)
    {
        return;
    }
    node*pindex=qs(head,tail);
    if(pindex==head)
    {
        quicksort(head,pindex);
    }
    else
    {
        node*temp=head;
        while(temp->next!=pindex)
        {
            temp=temp->next;
        }
        quicksort(head,temp);
    }
    quicksort(pindex->next,tail);
}
int main()
{
    node*head=NULL,*tail;
    cout<<"\nEnter the elements\n";
    int temp=0;
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
    //cout<<tail->data<<endl<<endl;
    quicksort(head,tail);
    node*t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
