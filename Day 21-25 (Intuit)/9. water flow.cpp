class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int preval, vector<vector<int>>& ocean) {
        if (row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size()) {
            return;
        }
        if (heights[row][col] < preval) {
            return;
        }
        if (ocean[row][col] == 1) {
            return;
        }
        ocean[row][col] = 1;
        dfs(heights, row + 1, col, heights[row][col], ocean);
        dfs(heights, row, col + 1, heights[row][col], ocean);
        dfs(heights, row - 1, col, heights[row][col], ocean);
        dfs(heights, row, col - 1, heights[row][col], ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        if (heights.size() == 0) {
            return ans;
        }
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        for (int i = 0;i < m;i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, n - 1, INT_MIN, atlantic);
        }
        for (int i = 0;i < n;i++) {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, m - 1, i, INT_MIN, atlantic);
        }
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({ i,j });
                }
            }
        }
        return ans;
    }
};