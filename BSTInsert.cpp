#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) 
        return new Node(key);    
    if (root->key == key) 
        return root;
    if (root->key < key) 
        root->right = insert(root->right, key);
    else 
        root->left = insert(root->left, key);
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    return 0;
}
