#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    list<int> ll;
    public:
    Stack(){
        
    }

    void push(int x){
        ll.push_front(x);
    }

    int pop(){
        if(ll.empty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int x = ll.front();
        ll.pop_front();
        return x;
    }

    int top(){
        if(ll.empty()){
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        return ll.front();
    }

    int size(){
        return ll.size();
    }

    bool empty(){
        return ll.empty();
    }
};

int main(int argc, char **argv){
    // Stack stk;
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}