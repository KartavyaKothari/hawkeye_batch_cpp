#include<bits/stdc++.h>
using namespace std;

class Queue{
    list<int> ll;
    public:
    void enqueue(int x){
        ll.push_back(x);
    }

    int dequeue(){
        if(ll.empty()){
            cout<<"Queue is empty";
            return -1;
        }
        
        int x = ll.front();
        ll.pop_front();

        return x;
    }

    int front(){
        return ll.front();
    }

    int back(){
        return ll.back();
    }

    int size(){
        return ll.size();
    }

    bool empty(){
        return ll.empty();
    }
};

int main(int argc, char **argv){
    // Queue queue;
    queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    queue.dequeue();
    queue.dequeue();

    while (!queue.empty())
    {
       cout<<queue.front()<<" "<<endl;
       queue.dequeue();
    }
    
    return 0;
}