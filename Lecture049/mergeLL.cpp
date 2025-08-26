/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

void solve(Node<int>* first, Node<int>* second) {
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    
    Node<int>* curr2 = second;
    Node<int>* next2 = NULL;

    // Edge case: if first list has only one node
    if(next1 == NULL) {
        curr1->next = curr2;
        return;
    }
    
    while(next1 != NULL && curr2 != NULL) {
        // Check if curr2 fits between curr1 and next1
        if(curr2->data >= curr1->data && curr2->data <= next1->data) {
            next2 = curr2->next;    // store next of curr2
            curr1->next = curr2;
            curr2->next = next1;
            
            // Move forward
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            // move forward in first list
            curr1 = next1;
            next1 = next1->next;
            
            // if we reached end of first list
            if(next1 == NULL) {
                curr1->next = curr2;
                return;
            }
        }
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first->data <= second->data) {
        solve(first, second);
        return first;
    }
    else {
        solve(second, first);
        return second;
    }
}
