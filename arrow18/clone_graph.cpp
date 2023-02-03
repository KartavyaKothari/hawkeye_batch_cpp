/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        
        unordered_map<int,Node *> nodes;
        nodes[1] = new Node(1);
        
        unordered_map<int,bool> visited;
        visited[1] = true;
        
        queue<Node *> next;
        next.push(node);
        
        Node *curr;
        Node *copy;
        
        while(!next.empty()){
            curr = next.front();
            next.pop();
            copy = nodes[curr->val];
            
            for(Node *child : curr->neighbors){
                if(nodes[child->val] == nullptr) 
                    nodes[child->val] = new Node(child->val);
                    
                copy->neighbors.push_back(nodes[child->val]);
                if(!visited[child->val]){
                    visited[child->val] = true;
                    next.push(child);
                }
            }
        }
        
        return nodes[1];
    }
};