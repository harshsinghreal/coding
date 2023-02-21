#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * prev;
    Node * Next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->Next = NULL;

    }

};
void InsertAtHead(Node *&head,int data){
    if (head==NULL)
    {
        Node*luca = new Node(data);
        head = luca;
        return;
    }
    
    Node *temp = head;
    Node*luca = new Node(data);
    while (temp->Next)
    {
        temp= temp->Next;
    }
    luca->Next=head;
    head->prev = luca;
    head = luca;
    
    
}
void print(Node*&head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->Next;
    }
    
}
int main(){
    Node * head = new Node(22);
    cout<<sizeof(Node);
    InsertAtHead(head,32);
    InsertAtHead(head,45);
    
    print(head);
    
    return 0;
}