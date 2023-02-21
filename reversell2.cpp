#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * Next;

        Node(int data){
            this->data = data;
            this->Next = NULL;

        }
};

void insert(Node * head,int data){
    Node *temp = new Node(data);
    Node *t=head;
    while(t->Next){
    t = t->Next;
    }
    t->Next= temp;
}

void print(Node * head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->Next;
    }
}

Node* reverse(Node *head){
    Node * curr=head;
    Node* prev=NULL;
    Node * agla=NULL;

    while (curr)
    {
        agla = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = agla;
    }
    head=prev;
    return head;
    
}

void addition(Node * head,Node * head2){
        Node* i=head, *j=head2;
        int sum=0,carry = 0;
        while(i!=NULL&&j!=NULL){
            sum=0;
            sum = sum + i->data + j->data;
            i=i->Next;
            j=j->Next;
            carry=sum%10;
            cout<<sum%10<<" ";
            

        }
        

}
int main(){
    Node * head = new Node(4);
    insert(head,2);
     insert(head,5);
      insert(head,6);
    print(head);
    cout<<endl<<endl;

    Node * head2 = new Node(1);
    insert(head2,2);
     insert(head2,3);
      insert(head2,9);
      print(head2);
      cout<<endl<<endl;
    // print(reverse(head2));
    // 
    // print(head);

    addition(head,head2);

    return 0;
}