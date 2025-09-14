class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();

        // process first window
        for (int i = 0; i < k; i++)
            if (arr[i] < 0) dq.push_back(i);

        ans.push_back(dq.empty() ? 0 : arr[dq.front()]);

        // process remaining windows
        for (int i = k; i < n; i++) {
            if (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            if (arr[i] < 0)
                dq.push_back(i);

            ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
        }
        return ans;
    }
};
