#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node * left;
    node * right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
   
};
void printTree(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

}

    node* buildTree(node * root){
        cout<<"enter the data ";
        int data;
        cin>>data;
        root = new node(data);
         if(data==-1) return NULL;

        root->left = buildTree(root->left);
        root->right = buildTree(root->right);

        return root;
    }






int main(){

    node* root = NULL;
    root = buildTree(root);
    printTree(root);
    return 0;
}