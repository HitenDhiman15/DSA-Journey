/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root == NULL) {
        return false;
    }

    if(root->data == x) {
        return true;
    }

    if(root->data > x) {
        //left part me
        return searchInBST(root->left, x);
    }

    if(root->data < x) {
        //right part me
        return searchInBST(root->right, x);
    }
}