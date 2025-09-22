/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Process all nodes in the current diagonal
            while (curr != nullptr) {
                result.push_back(curr->data);
                if (curr->left) {
                    q.push(curr->left); // Left child goes to the next diagonal
                }
                curr = curr->right; // Right child stays on the same diagonal
            }
        }

        return result;
    }
};
