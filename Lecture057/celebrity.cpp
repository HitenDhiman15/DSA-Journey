class Solution {
  private:
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }
    
  public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> s;

        // step1: push all people
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        // step2: eliminate non-celebrities
        while(s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            if(knows(M,a,b)) {
                // a knows b → a cannot be celeb
                s.push(b);
            }
            else {
                // a does not know b → b cannot be celeb
                s.push(a);
            }
        }
        
        int ans = s.top();
        
        // step3: verify candidate
        
        // Row check → all 0 except self
        for(int i=0; i<n; i++) {
            if(i != ans && M[ans][i] != 0) {
                return -1;
            }
        }
        
        // Column check → all 1 except self
        for(int i=0; i<n; i++) {
            if(i != ans && M[i][ans] != 1) {
                return -1;
            }
        }
        
        return ans;
    }
};
