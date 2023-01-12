#include<bits/stdc++.h>
using namespace std;

bool is_adult(int age){
    if (age > 21){
        return true;
    }

    return false;
}

int main(int argc, char **argv){
    int age;
    string name;

    cout << "Please enter you name: ";
    cin >> name;

    cout << "Please enter your age: ";
    cin >> age;

    cout << "Hi " << name << ", you are " << age << " years old" <<endl;
    if(is_adult(age)){
        cout << "You are eligible to drink in my bar"<<endl;
    }else{
        cout << "Sorry, come back in "<<21-age<<" years"<< endl;
    }
}