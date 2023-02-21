#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * Next;

         Node(int data){
            this->data = data;
            this->Next=NULL;
        }
};

void InsertAtHead(Node* &head, int data){
    Node * temp = new Node(data);
    temp->Next=head;
    head = temp;
}
void print(Node* &head){
    Node *temp = head;
    while(temp){
    cout<<temp->data<<" ";
    temp=temp->Next;
    }
}
void InsertAtTail(Node* &head,int data){
    Node * temp= head;
    Node * loca = new Node(data);
    while (temp->Next)
    {
        temp=temp->Next;
    }
    temp->Next= loca;
    
}
void InsertAtPos(Node* &head,int pos,int data){
    if(pos==0){
        InsertAtHead(head,data);
        return;
    }
    Node * loca = new Node(data);
    Node * temp = head;
    int n =1;
    while (n!=pos)
    {
        temp=temp->Next;
        n++;
    }
    loca ->Next = temp->Next;
    temp->Next = loca;
    
}

/////delete
void DeleteAtPos(Node * & head, int pos){
    Node * temp=head;
    int count=1;
     Node *q;
    if(pos==1){
        q = head;
        head = head->Next;
        q->Next=NULL;
        delete q;
        return;
    }
    while(count!=pos-1){
        temp=temp->Next;
        count++;
    }
   q= temp->Next;
   q->Next=NULL;
    temp ->Next = temp->Next->Next;
    delete q;
    
}


int main(){
    Node * head = new Node(10);
    InsertAtHead(head,12);
    
    InsertAtHead(head,32);
    InsertAtTail(head,43);
    InsertAtTail(head,83);
    InsertAtPos(head,0,55);
    print(head);
    cout<<endl;
    DeleteAtPos(head,1);
    print(head);
    return 0;
}