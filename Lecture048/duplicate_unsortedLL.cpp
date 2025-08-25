#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if (head == NULL) return head;

    unordered_set<int> seen;   // to store visited data
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            // Duplicate found ? remove node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
