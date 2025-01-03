#include<iostream>
using namespace std;

class Node{ //user defined data type6
public:
   int val;
   Node* next;

   Node(int val){
    this->val = val;
    this->next = NULL;
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
void insertAtEnd(int val){
    Node* temp = new Node(val);
    if(size==0) head =tail=temp;
    else{
        tail->next = temp;
        tail = temp;
    }
    size++;
}
void insertAtHead(int val){
    Node* temp = new Node(val);
    if(size==0) head =tail=temp;
    else{
        temp->next = head;
        head = temp;
    }
    size++;
}
void insertAtIndex(int idx, int val){
    if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
    else if(idx==0) insertAtHead(val);
    else if(idx==size)insertAtEnd(val);
    else{
    Node* t = new Node(val);
    Node* temp = head;
    for(int i =1; i<=idx-1;i++){
        temp = temp->next;
    }
    t->next = temp->next;
    temp->next = t;
    size++;

    }
  }
int getAtInx(int idx){
    if(idx<0 || idx>=size) {

    cout<<"Invalid Index"<<endl;
    return -1;
    }
    else if(idx==0) return head->val;
    else if(idx==size-1) return tail->val;
    else{
    Node* temp = head;
    for(int i =1; i<=idx-1;i++){
        temp = temp->next;
    }
    return temp->val;
     
}  }
void deleteAtHead(){
    if(size==0){
        cout<<"List is empty";
    }
    head = head->next;
    size--;
}
void deleteAtTail(){
    if(size==0){
        cout<<"List is empty";
        return;
    }

    Node* temp =  head;
    while(temp -> next!=tail){
        temp = temp->next;
    }
    temp->next=NULL;
    tail = temp;
    size--;
}

void deleteAtIndex(int idx){
    if(size==0){
     cout<<"List is empty"<<endl;
     return;
    }
    else if(idx<0 || idx>size){
     cout<<"Invalid Index"<<endl;
     return;
    }
    else if(idx==0) return deleteAtHead();
    else if(idx==size-1) return deleteAtTail();
    else{
    Node* temp = head;
    for(int i =1; i<=idx-1;i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    size--;
}}

void delete(int val){
    if(size==0){
     cout<<"List is empty"<<endl;
     return;
    }
    else{

    }

}
void display(){
   Node* temp = head;
   while(temp!= NULL){
    cout<<temp->val<<" ";
    temp = temp->next;
   }
   cout<<endl;

}

};


int main(){
    LinkedList ll ;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(40);
    ll.display();  
    cout<<ll.size<<endl;
    ll.insertAtHead(60);
    ll.display();  
    ll.insertAtIndex(3,30);
    ll.display();  
    cout<<ll.getAtInx(4)<<endl;
    ll.deleteAtHead();
    ll.display(); 
    ll.deleteAtTail();
    ll.display(); 
    ll.deleteAtIndex(1);
    ll.display(); 


}