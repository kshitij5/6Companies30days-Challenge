// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // using dfs
    //  all we had to do is to find if the directed graph contains any cycle
    bool dfs(int src, vector<bool>& visited, vector<bool>& recstack, vector<int> adj[]) {
        if (!visited[src]) {
            // mark visited
            visited[src] = true;
            recstack[src] = true;

            //  visiting its all adjacent nodes
            for (auto it : adj[src]) {
                if (!visited[it]) {
                    if (dfs(it, visited, recstack, adj))
                        return true;
                }
                else if (recstack[it]) {
                    return true;
                }

            }
        }
        recstack[src] = false;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        // create a directed graph of all the edges
        vector<int>adj[N];

        // creating adjency matrix
        for (auto it : prerequisites) {
            int u = it.first, v = it.second;
            adj[u].push_back(v);
        }

        vector<bool>visited(N, false);
        vector<bool>recstack(N, false);

        // dfs if not visited
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, recstack, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends