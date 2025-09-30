/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* temp = root;
    int pred = -1;
    int succ = -1;

    // Search for the key, updating pred and succ on the way
    while(temp != NULL && temp->data != key) {
        if(temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        }
        else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // ? If key not found, avoid null pointer dereference
    if(temp == NULL) {
        return {pred, succ};
    }

    // Find predecessor (rightmost node in left subtree)
    TreeNode* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find successor (leftmost node in right subtree)
    TreeNode* rightTree = temp->right;
    while(rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}
