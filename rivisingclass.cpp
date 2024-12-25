#include<iostream>
using namespace std;
class Student{  //user defined data type
public:
    string name;
    int rno;
    float marks;

Student(string name,int rno, float marks){


    this->name = name;
    this->rno = rno;
    this->marks = marks;

}


};
// void change(Student s){
//     s.name = "Harsh";
// }

int main (){
    Student s("aman",73,89);
    //here we make pointer
    Student* a = new Student("aaaaaman",73,89);
    cout<<s.name<<endl;
    Student * ptr = &s;
    ptr->name = "harsh";
    cout<<s.name<<endl;
    (*ptr).name = "aman";
    cout<<a->name<<endl;


}
