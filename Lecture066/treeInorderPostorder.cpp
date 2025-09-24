/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Create a map from node value to its index in inorder
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for(int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    Node* solve(vector<int>& inorder, vector<int>& postorder, int& index, 
                int inorderStart, int inorderEnd, int n, map<int, int>& nodeToIndex) {
        
        // Base case
        if(index < 0 || inorderStart > inorderEnd) {
            return nullptr;
        }

        int element = postorder[index--];
        Node* root = new Node(element);

        int position = nodeToIndex[element];

        // Build right subtree first for postorder
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n - 1;

        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);

        return solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
    }
};