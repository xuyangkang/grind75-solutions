const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<int> q;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, m + n));
        vector<vector<bool>> visited(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    visited[i][j] = true;
                    q.push(i);
                    q.push(j);
                }
            }
        }
        
        while (q.size() > 0) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            for (const auto d : DIRECTIONS) {
                int new_x = x + d[0];
                int new_y = y + d[1];
                if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
                    continue;
                }
                if (ans[new_x][new_y] > ans[x][y] + 1) {
                    ans[new_x][new_y] = ans[x][y] + 1;
                    if (!visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        q.push(new_x);
                        q.push(new_y);
                    }
                }
            }
        }
        
        return ans;
    }
};