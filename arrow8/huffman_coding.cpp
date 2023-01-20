#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int freq;
    bool is_leaf;
    char alpha;
    
    Node* left;
    Node* right;

    Node(int freq, char c){
        freq = freq;
        alpha = c;
        is_leaf = true;
        left = nullptr;
        right = nullptr;
    }

    Node(Node* left, Node* right){
        freq = left->freq+right->freq;
        is_leaf = false;
        left = left;
        right = right;
    }
};

auto comp = [&](Node* a, Node* b){return a->freq > b->freq;};

// priority_queue<int,vector<int>,greater<int>()> pq;

class HuffmanTree{
    priority_queue<
        Node*,
        vector<Node*>,
        decltype(comp)
        // greater<int>()
    > huff_tree;

    // Node* combine_nodes(Node* first, Node* second){
    //     vector<char> arr;
    //     merge(
    //             first->alphabets.begin(),
    //             first->alphabets.end(),
    //             second->alphabets.begin(),
    //             second->alphabets.end(),
    //             arr.begin()
    //         );

    //     return new Node(
    //         first->freq+second->freq,
    //         arr
    //     );
    // }
    public:
    void push(Node* node){
        huff_tree.push(node);
    }

    Node* top(){
        return huff_tree.top();
    }

    void pop(){
        if(huff_tree.empty()){
            cout<<"Empty"<<endl;
            return;
        }
        huff_tree.pop();
    }

    void build_tree(){

    }
};

int main(int argc, char **argv){

    return 0;
}