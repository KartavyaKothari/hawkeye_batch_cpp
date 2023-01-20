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
        this->freq = freq;
        this->alpha = c;
        this->is_leaf = true;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(Node* left, Node* right){
        this->freq = left->freq+right->freq;
        this->is_leaf = false;
        this->left = left;
        this->right = right;
    }
};

class Compa{
    public:
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

class HuffmanTree{
    priority_queue<
        Node*,
        vector<Node*>,
        Compa
    > huff_heap;

    unordered_map<char,string> encoder_table;

    public:
    HuffmanTree(){
        // huff_heap(comp);
    }

    void push(Node* node){
        huff_heap.push(node);
    }

    Node* top(){
        return huff_heap.top();
    }

    Node* pop(){
        if(huff_heap.empty()){
            cout<<"Empty"<<endl;
            return nullptr;
        }
        Node* n = huff_heap.top();
        huff_heap.pop();
        return n;
    }

    void encoder(Node* curr,string bin_code_till_now){
        if(curr == nullptr) return;
        if(curr->is_leaf) {
            encoder_table[curr->alpha] = bin_code_till_now;
            return;
        }

        encoder(curr->left, bin_code_till_now+"0");
        encoder(curr->right, bin_code_till_now+"1");
    }

    void display_encoder(){
        for(auto c_code: encoder_table){
            cout<<c_code.first<<" : "<<c_code.second<<endl;
        }
    }

    void build_tree(string text){
        unordered_map<char,int> freq_table;
    
        for(char c: text){
            // if(freq_table.find(c)==freq_table.end()) freq_table[c] = 0;
            freq_table[c]++;
        }

        for(auto c_freq: freq_table){
            // cout<<c_freq.first<<" "<<c_freq.second<<endl;
            huff_heap.push(new Node(
                c_freq.second,
                c_freq.first
            ));
            // cout<<huff_heap.size()<<endl;
        }

        while(huff_heap.size()>1){
            Node* first = pop();
            Node* second = pop();
            // cout<<first->freq<<" "<<second->freq<<endl;
            push(new Node(first, second));
        }

        Node* tree = pop();
        encoder(tree,"");

        display_encoder();
    }

    // ON A BREAK TILL 9:55

};

int main(int argc, char **argv){
    string text;
    cin>>text;

    HuffmanTree* h_code = new HuffmanTree();
    h_code->build_tree(text);

    return 0;
}