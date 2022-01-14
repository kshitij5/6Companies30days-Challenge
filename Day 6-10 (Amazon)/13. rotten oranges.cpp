class Solution {
public:
    // using dfs
//     int orangesRotting(vector<vector<int>>& grid) {
//         return dfs(grid, 0, 1, 0)+dfs(grid, 1, 0, 0);
//     }
//     int dfs(vector<vector<int>>& grid,int i, int j, int count) {
//         if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]==2)
//             return 0;

//         if(grid[i][j]) {
//             grid[i][j] = 2;
//             count++;
//             dfs(grid, i, j-1, count);
//             dfs(grid, i-1, j, count);
//             dfs(grid, i, j+1, count);
//             dfs(grid, i+1, j, count);
//         }
//         return count;
//     }


    // using bfs which is more optimised for this kind of solutions

    int orangesRotting(vector<vector<int>>& grid) {
        //number of valid cells (cells with some orange)
        int ct = 0;
        //result
        int res = -1;
        //actually queue of pairs of coord i and j
        queue<vector<int>> q;

        //ways to move
        vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        //create starting nodes to queue to do bfs
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                //increasing number of valid cells
                if (grid[i][j] > 0)
                    ct++;

                //only rotten oranges must be on initial step of queue
                if (grid[i][j] == 2)
                    q.push({ i, j });
            }
        }

        //bfs
        while (!q.empty()) {

            //we do one step from rotten
            res++;

            //see next comment
            int size = q.size();

            //need to start from all rotten nodes at one moment 
            for (int k = 0; k < size; k++) {

                //take node from head
                vector<int> cur = q.front();
                q.pop();

                //number of valid decreasing
                ct--;

                //need to look through all four directions
                for (int i = 0; i < 4; i++) {
                    //taking coords
                    int x = cur[0] + dir[i][0];
                    int y = cur[1] + dir[i][1];

                    //if we go out of border or find non-fresh orange, we skip this iteration
                    if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1)
                        continue;

                    //orange becomes rotten
                    grid[x][y] = 2;

                    //this orange will make neighbor orange rotten
                    q.push({ x, y });
                }
            }
        }
        //if we looked through all oranges, return result, else -1
        return (ct == 0) ? max(0, res) : -1;
    }
};