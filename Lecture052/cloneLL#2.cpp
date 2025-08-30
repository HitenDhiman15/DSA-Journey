/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  private:
  void insertAtTail(Node* &head, Node* &tail, int d) {
      Node* newNode = new Node(d);
      
      if(head == NULL) {
          head = newNode;
          tail = newNode;
      }
      else {
          tail -> next = newNode;
          tail = newNode;
      }
  }
  
  public:
    Node* cloneLinkedList(Node* head) {
        if(head == NULL) return NULL;
        
        // step1: create a clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        // step2: cloneNodes add in between Original List
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        // step3: random pointer copy (FIXED: use curr instead of temp)
        Node* curr = head;
        while(curr != NULL) {
            if(curr -> next != NULL) {
                curr -> next -> random = curr -> random ? curr -> random -> next : NULL;
            }
            curr = curr -> next -> next; 
        }
        
        // step4: revert changes done in step2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL) {
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        // step5: return ans;
        return cloneHead;
    }
};
