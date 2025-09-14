class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> count;
        queue<char> q;            // queue of characters
        string ans = "";

        for (int i = 0; i < (int)s.length(); i++) {
            char ch = s[i];

            // increase count
            count[ch]++;

            // push to queue
            q.push(ch);

            // remove all repeating chars from front
            while (!q.empty() && count[q.front()] > 1) {
                q.pop();
            }

            // record the first non-repeating char or '#'
            if (q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }
        return ans;   
    }
};
