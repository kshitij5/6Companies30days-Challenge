// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
public:
    // sliding window
    // tc - o(n)
    // sc - o(n)
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod = 1, res = 0, left = 0, right = 0;

        for (right = 0; right < n; right++) {
            prod *= a[right];

            while (left < n && prod >= k) {
                prod /= a[left];
                left++;
            }

            if (prod < k) {
                res += (right - left + 1);
            }
        }
        return (int)res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends