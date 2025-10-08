#include<bits/stdc++.h>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// In-order traversal to store BST nodes in sorted order
void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Pre-order traversal to convert BST to Min Heap using in-order data
void bstToMinHeap(Node* root, vector<int>& inorder, int& index) {
    if (!root) return;
    root->data = inorder[index++];
    bstToMinHeap(root->left, inorder, index);
    bstToMinHeap(root->right, inorder, index);
}

// Utility function to convert BST to Min Heap
void convertBSTToMinHeap(Node* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int index = 0;
    bstToMinHeap(root, inorder, index);
}

// Pre-order traversal to print the tree
void preorderPrint(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// Helper function to insert a node in BST
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

// Example usage
int main() {
    Node* root = nullptr;
    root = insertBST(root, 8);
    root = insertBST(root, 4);
    root = insertBST(root, 12);
    root = insertBST(root, 2);
    root = insertBST(root, 6);
    root = insertBST(root, 10);
    root = insertBST(root, 14);

    convertBSTToMinHeap(root);

    cout << "Min Heap (Pre-order): ";
    preorderPrint(root);
    cout << endl;

    return 0;
}
