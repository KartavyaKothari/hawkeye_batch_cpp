#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *right;

    Node (int data){
        this->data = data;
        this->right = nullptr;
    }
};

class LL{
    public:

    Node *head;
    Node *tail;

    Node* insert_front(int data){
        Node* n = new Node(data);

        if(head == nullptr){
            head = n;
            tail = n;
            return n;
        }

        n->right = head;
        head = n;

        return n;
    }

    LL(){
        head = nullptr;
        tail = nullptr;

        insert_front(0);
        insert_front(10);
        insert_front(20);
        insert_front(30);
        Node* temp = insert_front(40);
        insert_front(50);
        insert_front(60);
        // tail->right = temp;
    }

    void display(){
        if(is_loop_present()){
            cout << "Loop present" << endl;
            return;
        }
        Node* q = head;

        while(q!= nullptr){
            cout << q->data << " ";
            q = q->right;
        }
    }

    bool is_loop_present(){
        Node *tortoise = head;
        Node *hare = head;

        int i = 0;

        cout<<"Step "<<i<<">> "; i++;
        cout<<"Tortoise: "<<tortoise->data<<" ";
        cout<<"Hare: "<<hare->data<<" "<<endl;

        while(tortoise!= nullptr && hare!= nullptr && hare->right!= nullptr){
            tortoise = tortoise->right;
            hare = hare->right->right;

            cout<<"Step "<<i<<">> "; i++;
            cout<<"Tortoise: "<<tortoise->data<<" ";
            cout<<"Hare: "<<hare->data<<" "<<endl;

            if(tortoise == hare){
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char **argv){
    LL ll;
    ll.display();
    return 0;
}