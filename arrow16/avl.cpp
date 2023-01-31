// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node{
	public:
	int key;
	Node *left;
	Node *right;
	int height;

    Node(int key){
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1; 
    }
};

class AVL_Tree{
    Node *root;
    public:
    AVL_Tree(){
        root = nullptr;
    }

    int height(Node *N){
        if (N == nullptr)
            return 0;
        return N->height;
    }

    Node *rightRotate(Node *T){
        Node *P = T->left;
        Node *N = P->right;

        // Perform rotation
        T->left = P->right;
        P->right = T;

        // Update heights
        T->height = max(height(T->left),
                        height(T->right)) + 1;
        P->height = max(height(P->left),
                        height(P->right)) + 1;

        // Return new root
        return P;
    }

    Node *leftRotate(Node *T){
        Node *P = T->left;
        Node *N = P->right;

        // Perform rotation
        T->right = P->left;
        P->left = T;

        // Update heights
        T->height = max(height(T->left),
                        height(T->right)) + 1;
        P->height = max(height(P->left),
                        height(P->right)) + 1;

        // Return new root
        return P;
    }

    // Get Balance factor of node N
    int getBalance(Node *N){
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    void insert(int key){
        root = insert(root,key);
    }

    Node* insert(Node* node, int key){
        if (node == nullptr)
            return(new Node(key));

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left),
                            height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    void display(){
        preOrder(root);
    }
    
    void preOrder(Node *root)
    {
        if(root != nullptr)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main(){
	
	AVL_Tree tree;
	
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(25);
	
    tree.display();
	
	return 0;
}

// Short break till 10:30