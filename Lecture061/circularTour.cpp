class Solution {
public:
    int startStation(const vector<int> &gas, const vector<int> &cost) {
        int n = gas.size();
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        return (deficit + balance >= 0) ? start : -1;
    }
};
