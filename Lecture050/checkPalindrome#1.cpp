/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/
#include<bits/stdc++.h>

class Solution {
  private:
    bool checkPalindrome(vector<int> arr) {
        
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e) {
            
            if(arr[s] != arr[e]) {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    
  public:
    bool isPalindrome(Node *head) {
        vector<int> arr;
        
        Node* temp = head;
        while(temp != NULL) {
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        
        return checkPalindrome(arr);
    }
};