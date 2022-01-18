// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return 0;

        if (!grid[x][y])
            return 0;

        grid[x][y] = 0;

        return 1 + dfs(grid, x - 1, y)
            + dfs(grid, x + 1, y)
            + dfs(grid, x, y - 1)
            + dfs(grid, x, y + 1)
            + dfs(grid, x - 1, y - 1)
            + dfs(grid, x + 1, y + 1)
            + dfs(grid, x + 1, y - 1)
            + dfs(grid, x - 1, y + 1);
    }
public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j])
                    max_area = max(dfs(grid, i, j), max_area);
            }
        }

        return max_area;
    }

};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends