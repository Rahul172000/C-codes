#include<iostream>
using namespace std;
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST {
    BinaryTreeNode<int> *root;
    bool hd(int data,BinaryTreeNode<int> *root){
        if(root==NULL)
            return false;
        if(root->data==data)
            return true;
        else if(root->data>data)
        {
            return hd(data,root->left);
        }
        else
            return hd(data,root->right);
    }
    BinaryTreeNode<int> * ins(int data,BinaryTreeNode<int> *root){
         if(root==NULL)
        {
            BinaryTreeNode<int> * temp=new BinaryTreeNode<int> (data);
            return temp;
        }
        else if(root->data<data)
        {root->right=ins(data,root->right);}
        else
            {root->left=ins(data,root->left);}
        return root;
    }
    BinaryTreeNode<int> * del(int data,BinaryTreeNode<int> * node){
        if(node==NULL)
        {return NULL;}
        if(data>node->data)
        {
            node->right=del(data,node->right);
            return node;
        }
        else if(data<node->data){
            node->left=del(data,node->left);
            return node;
        }else {
            if(node->left==NULL && node->right==NULL)
            {
                delete node;
                return NULL;
            }else if(node->left==NULL)
            {
                BinaryTreeNode<int> * temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }else if(node->right==NULL)
            {
                BinaryTreeNode<int> * temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }else {
                BinaryTreeNode<int> * minnode=node->right;
                while(minnode->left!=NULL)
                {minnode=minnode->left;}
                int rightmin=minnode->data;
                node->data=rightmin;
                node->right=del(rightmin,node->right);
                return node;
            }
        }
    }
    void print(BinaryTreeNode<int> * root){
        if(root==NULL)
        {return;}
     cout<<root->data<<":";
     if(root->left!=NULL)
     {cout<<"L:"<<root->left->data<<",";}
      if(root->right!=NULL)
     {cout<<"R:"<<root->right->data;}
     cout<<endl;
     print(root->left);
     print(root->right);
    }
   public:
   BST()
   {root=NULL;}
   ~BST()
   {delete root;}
   bool hasData(int data)
   {return hd(data,root);}
   void insert(int data)
   {root=ins(data,root);}
   void deleteData(int data)
   {root=del(data,root);}
   void printTree()
   {print(root);}
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cout<<"\n1.Insert 2.Delete 3.Search 4.Print 5.Quit ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter the data to be inserted ";
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cout<<"\nEnter the data to be deleted ";
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cout<<"\nEnter the data to be searched ";
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            case 4:
                tree->printTree();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"\nNo such option";
        }
    }
}
