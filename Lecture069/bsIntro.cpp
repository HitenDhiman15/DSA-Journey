#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

Node* minVal(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    //base case
    if(root == NULL) {
        return root;
    }

    if(root->data == val) {
        //0 chile
        if(root->left == NULL && root-<right == NULL) {
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > val) {
        //left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else 
    {
        //right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// ✅ Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ✅ Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ✅ Postorder Traversal (LRN)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ✅ Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (end with -1):" << endl;
    takeInput(root);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal of BST: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal of BST: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Min value is " << minVal(root) -> data << endl;

    cout << "Max value is " << maxVal(root) -> data << endl;

    //deletion
    root = deleteFromBST(root, 30);

    cout << "Enter data to create BST (end with -1):" << endl;
    takeInput(root);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal of BST: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal of BST: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Min value is " << minVal(root) -> data << endl;

    cout << "Max value is " << maxVal(root) -> data << endl;

    return 0;
}
