#include<iostream>
using namespace std;

//new data type with value and adress
class Node{
public:
   int val;
   Node * next;

   Node(int val){
    this->val = val;
    this->next = NULL;
   }
     
};

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int size(Node * head){
     Node* temp = head;
    cout<<"this is size of Linked List"<<endl;
    int n=0;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    cout<< n;
}
// delete from value/target
Node * deletenode(Node*head,Node* target){
    if(head==target){
    head = head->next;
    return head;
    }
    Node* temp = head;
    while (temp->next!=target){
        temp = temp->next;
    }
    temp->next =temp->next->next;
}
int main (){        
        Node* a = new Node(100);
        Node* b = new Node(200);
        Node* c = new Node(300);
        Node* d = new Node(400);
        a->next = b;
        b->next = c;
        c->next = d;
        Node* head = a;

        display(head);

        head = deletenode(head,a);
        display(head);


}
