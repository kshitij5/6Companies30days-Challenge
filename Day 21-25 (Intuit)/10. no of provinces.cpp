class Solution {
public:
    int c = 0;
    map<int, int> visited;
    int findCircleNum(vector<vector>& isConnected) {
        int n = isConnected.size();
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (isConnected[i][j] == 1) { isConnected[i][j] = j; }
                else { isConnected[i][j] = -1; }
            }
        }
        int x = 0;
        int region = 0;
        while (visited.size() != n) {
            dfs(isConnected, x);
            if (c == 0) { region++; }
            x++;

        }
        return region;


    }

    void dfs(vector<vector<int>>& graph, int currCity) {
        if (visited[currCity] == 0) {
            visited[currCity] = 1;
            for (int i = 0;i < graph[currCity].size();i++) {
                if (graph[currCity][i] != -1) { dfs(graph, graph[currCity][i]); }
                c = 0;
            }
        }
        else { c = 1; }
    }
};