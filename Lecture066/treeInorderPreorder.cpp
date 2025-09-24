// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Finds the position of the element in the inorder array between start and end
    int findPosition(vector<int>& inorder, int element, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd, int n) {
        // Base case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[index++];
        Node* root = new Node(element);
        int position = findPosition(inorder, element, inorderStart, inorderEnd);

        // Recursive calls
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        return solve(inorder, preorder, preOrderIndex, 0, n - 1, n);
    }
};
