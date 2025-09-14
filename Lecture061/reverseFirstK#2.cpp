class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // handle invalid k
        if (k <= 0 || k > (int)q.size()) return q;

        stack<int> s;

        // step 1: pop first k elements into stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // step 2: push them back from stack (reversed)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // step 3: move the remaining (n-k) elements to the back
        int t = q.size() - k;
        while (t--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
