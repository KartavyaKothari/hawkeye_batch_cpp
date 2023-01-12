#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

class linked_list{
    Node* head;
    Node* tail;
    public:
    linked_list(){
        head = nullptr;
        tail = nullptr;
    }

    void insert_front(int data){
        Node* n = new Node(data);

        if(head == nullptr){
            head = n;
            tail = n;
            return;
        }

        n->next = head;
        head = n;
    }

    void insert_back(int data){
        Node* n = new Node(data);

        if(tail == nullptr){
            head = n;
            tail = n;
            return;
        }

        tail->next = n;
        tail = n;
    }
};

int main(int argc, char **argv){


    return 0;
}