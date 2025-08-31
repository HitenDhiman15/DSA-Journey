/*
 * Definition for linked list.
 * class Node {
 *  public:
 *      int data;
 *      Node *next;
 *      Node *child;
 *      Node() : data(0), next(nullptr), child(nullptr) {};
 *      Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *      Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result = NULL;

    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    } else {
        result = b;
        result->child = merge(a, b->child);
    }

    result->next = NULL;  // ensure no next pointer interferes
    return result;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Flatten the rest of the list
    Node* rest = flattenLinkedList(head->next);

    // Break next link (important to avoid runtime errors / cycles)
    head->next = NULL;

    // Merge current list with rest
    head = merge(head, rest);

    return head;
}
