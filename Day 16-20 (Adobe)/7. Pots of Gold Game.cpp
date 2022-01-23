// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>& arr, int n)
    {
        // similar to optimal stragedy game
        vector<vector<int>> dp(n, vector<int>(n));

        // using dp gap method
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; j++, i++) {
                if (gap == 0) {
                    dp[i][j] = arr[i];
                }
                else if (gap == 1) {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else {
                    // when i pick ith pot
                    // opponent will pick either i+1th pot, in that case i can pick from i+2 - j
                    // or he can pick jth pot, in that case i can pick from i+1 - j-1
                    int vali = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    // same when j pick jth pot
                    int valj = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                    // I will pick such value which will give me overall win
                    // for that i-to-j interval
                    int val = max(vali, valj);

                    dp[i][j] = val;
                }
            }
        }

        return dp[0][n - 1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends