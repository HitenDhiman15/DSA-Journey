/*************************************************************

    Following is the Binary Tree node structure:

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

void inorder(TreeNode *root, vector<int> &in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void convertIntoSortedDLL(TreeNode *root, TreeNode* &head) {
    if (root == NULL) return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode* mergeLinkedList(TreeNode *head1, TreeNode *head2) {
    TreeNode *head = NULL, *tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        TreeNode *node = NULL;
        if (head1->data < head2->data) {
            node = head1;
            head1 = head1->right;
        } else {
            node = head2;
            head2 = head2->right;
        }

        node->left = node->right = NULL;

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->right = node;
            node->left = tail;
            tail = node;
        }
    }

    while (head1 != NULL) {
        TreeNode *next = head1->right;
        head1->left = head1->right = NULL;
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = next;
    }

    while (head2 != NULL) {
        TreeNode *next = head2->right;
        head2->left = head2->right = NULL;
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = next;
    }

    return head;
}

int countNodes(TreeNode *head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->right;
    }
    return cnt;
}

TreeNode* sortedLLToBST(TreeNode* &head, int n) {
    if (n <= 0 || head == NULL)
        return NULL;

    TreeNode *left = sortedLLToBST(head, n / 2);

    TreeNode *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    TreeNode *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    if (head1) head1->left = NULL;

    TreeNode *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    if (head2) head2->left = NULL;

    TreeNode *mergedDLL = mergeLinkedList(head1, head2);

    int n = countNodes(mergedDLL);
    TreeNode *mergedBST = sortedLLToBST(mergedDLL, n);

    vector<int> result;
    inorder(mergedBST, result);  // To return the sorted values
    return result;
}
