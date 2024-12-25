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
int main (){
       // 10 20 30 40 
       Node a(10);
       Node b(20);
       Node c(30);
       Node d(40);
       a.next = &b;
       b.next = &c;
       c.next = &d;
cout<<"print value of b with help of a"<<endl;
     cout<<(a.next)->val<<endl;
     a.next->val = 70;
     cout<<(a.next)->val<<endl;
cout<<"print value of d with help of a"<<endl;
     cout<<a.next->next->next->val<<endl;
cout<<"print values in Lisnk list"<<endl;
Node temp = a;
while(1){
    cout<<temp.val<<" ";
    if(temp.next == NULL) break;
    temp = *(temp.next);
}

        
// other way to declear node using pointer
cout<<endl<<"print values of other list"<<endl;
        Node* w = new Node(100);
        Node* x = new Node(200);
        Node* y = new Node(300);
        Node* z = new Node(400);
        w->next = x;
        x->next = y;
        y->next = z;

        Node *tem = w;
    while(tem!=NULL){
        cout<<tem->val<<" ";
        tem = tem->next;
    }
cout<<endl<<"print value of z with help of w"<<endl;
     cout<<w->next->next->next->val<<endl;
     display(w);
     size(w);


}
