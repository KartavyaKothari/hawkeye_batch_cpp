#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
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

        head->prev = n;
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

        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    void insert_after(Node* q, int data){
        if(q == nullptr || q->next == nullptr){
            insert_back(data);
            return;
        }

        Node* n = new Node(data);
        Node* s = q->next;

        n->prev = q;
        q->next = n;

        n->next = s;
        s->prev = n;
    }

    void display(){}
};

int main(int argc, char **argv){
    linked_list ll;

    

    return 0;
}