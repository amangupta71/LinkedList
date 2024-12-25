#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{  //user defined data structure
public:
    Node* head;   
    Node* tail;
    int size;
    LinkedList(){
    head = tail = NULL;
    size = 0;
    }

void rotatell(int k){
    if (head == NULL || k <= 0 || k >= size) {
        // No rotation needed if list is empty, k <= 0, or k >= size
        return;
    }

      Node* temp = head;
        Node* tempc;
        Node* t;
        while(temp){
            temp = temp->next;
            tempc = temp;
            size++;
        }
        int n=size;
        
        for(int i=1;i=n-k;i++){
            temp = temp->next;
            t = temp;
        }

        tempc->next = temp;
        t->next= t->next->next;
    }


void display(){
   Node* temp = head;
   while(temp!= NULL){
    cout<<temp->val<<" ";
    temp = temp->next;
   }
   cout<<endl;

}
void insertAtEnd(int val){
    Node* temp = new Node(val);
    if(size==0) head =tail=temp;
    else{
        tail->next = temp;
        tail = temp;
    }
    size++;
}
        };
int main(){
     LinkedList ll ;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);
    ll.display();
    ll.rotatell(3);
    ll.display();
}