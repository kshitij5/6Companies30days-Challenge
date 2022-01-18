// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // using derived method from 2sum & 3sum
    vector<vector<int> > fourSum(vector<int>& arr, int k) {
        int N = arr.size();
        vector<vector<int>> res;

        // for increasing effeciency while finding fourth variable
        sort(arr.begin(), arr.end());

        // for 1st variable combination
        for (int i = 0; i < N - 1; i++) {
            // for 2st variable combination
            for (int j = i + 1; j < N; j++) {
                // letting the 3rd variable
                int X = k - (arr[i] + arr[j]);
                int lo = j + 1, hi = N - 1;

                // finding the fourth variable
                // using binary search
                while (lo < hi) {
                    if (arr[lo] + arr[hi] < X)
                        lo++;
                    else if (arr[lo] + arr[hi] > X)
                        hi--;
                    else {
                        // unique quadruple found
                        vector<int> temp = { arr[i], arr[j], arr[lo], arr[hi] };
                        res.push_back(temp);

                        // handling duplicate elements
                        while (lo < hi && arr[lo] == temp[2]) lo++;
                        while (lo < hi && arr[hi] == temp[3]) hi--;
                    }
                }
                while (j + 1 < N && arr[j + 1] == arr[j]) j++;
            }
            while (i + 1 < N - 1 && arr[i + 1] == arr[i]) i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto& v : ans) {
            for (int& u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends