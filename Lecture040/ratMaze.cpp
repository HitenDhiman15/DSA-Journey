class Solution {
private:
    // Check if the rat can move to (x,y)
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
        return (x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (maze[x][y] == 1);
    }
    
    // Recursive backtracking function
    void solve(vector<vector<int>>& maze, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string& path) {
        // Base case: reached destination
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        
        // Mark this cell as visited
        visited[x][y] = 1;
        
        // Directions: D, L, R, U with corresponding coordinate moves
        // Down
        int newX = x + 1, newY = y;
        if (isSafe(newX, newY, n, visited, maze)) {
            path.push_back('D');
            solve(maze, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        // Left
        newX = x; newY = y - 1;
        if (isSafe(newX, newY, n, visited, maze)) {
            path.push_back('L');
            solve(maze, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        // Right
        newX = x; newY = y + 1;
        if (isSafe(newX, newY, n, visited, maze)) {
            path.push_back('R');
            solve(maze, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        // Up
        newX = x - 1; newY = y;
        if (isSafe(newX, newY, n, visited, maze)) {
            path.push_back('U');
            solve(maze, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        // Backtrack
        visited[x][y] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        if (n == 0 || maze[0][0] == 0) {
            return ans;
        }
        
        int srcX = 0, srcY = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        string path = "";
        solve(maze, n, ans, srcX, srcY, visited, path);
        
        // Sort the paths lex order as required
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
