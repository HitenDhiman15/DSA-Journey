#include<bits/stdc++.h>
class SpecialStack {
    stack<int> s;
    int mini;

    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()) {
            return ;
        }

        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return ;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return ;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) {
            return -1;
        }

        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) {
            return -1;
        }

        return mini;
    }  
};