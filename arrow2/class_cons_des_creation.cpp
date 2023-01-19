#include<bits/stdc++.h>
using namespace std;

class Student{
    // By default private variables
    int roll_no;
    string name;
    
    public:
    Student(){

    }

    Student(int roll_no, string name){
        this->roll_no = roll_no;
        this->name = name;
    }

    ~Student(){
        cout<<"Destructor is called"<<endl;
    }

    void print_info(){
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

int main(int argc, char **argv){
    // Student student;
    // Student student(24,"Kartavya");
    // Student student = Student(24,"Kartavya");
    Student* student = new Student(24,"Kartavya");
    student->print_info();

    // student.name;

    return 0;
}


// BREAK TILL 10:45