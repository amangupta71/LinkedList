#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class DLL{  //user defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
    head = tail = NULL;
    size = 0;
    }
void insertAtEnd(int val){
    Node* temp = new Node(val);
    if(size==0) head =tail=temp;
    else{
        tail->next = temp;  
        tail->prev = tail;
        tail = temp;

    }
    size++;
}
void insertAtHead(int val){
    Node* temp = new Node(val);
    if(size==0) head =tail=temp;
    else{
        temp->next = head;
        head->prev = NULL;
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
    t->prev = temp;
    t->next->prev=t;
    size++;

    }
  }

void deleteAtHead(){
    if(size==0){
        cout<<"List is empty";
        return;
    }
    head = head->next;
    if(head) head->prev=NULL;  //extra
    if(head==NULL) tail=NULL;        //extra

    size--;
}
void deleteAtTail(){
    if(size==0){
        cout<<"List is empty";
        return;
    }
    else if(size==1){              //extra
        deleteAtHead();
        return;
    }

    Node* temp =  tail->prev;
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
    temp->next->prev= temp;
    size--;
}}
int getAtInx(int idx){
    if(idx<0 || idx>=size) {

    cout<<"Invalid Index"<<endl;
    return -1;
    }
    else if(idx==0) return head->val;
    else if(idx==size-1) return tail->val;
    else{
        if(idx<size/2){
        Node* temp = head;
        for(int i =1; i<=size-1;i++){
        temp = temp->next;
    }
           return temp->val;
    }
    else{
        Node* temp = tail;
        for(int i =1; i<size-idx;i++){
        temp = temp->prev;
    }
    return temp->val;
        }
     
}  }

// void delete(int val){
//     if(size==0){
//      cout<<"List is empty"<<endl;
//      return;
//     }
//     else{

//     }

// }
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
    DLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display();
    list.insertAtHead(60);
    list.display();
    list.insertAtIndex(2,80);
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtIndex(3);
    list.display();
    list.deleteAtTail();
    list.display();
    cout<<list.getAtInx(1)<<endl;

}