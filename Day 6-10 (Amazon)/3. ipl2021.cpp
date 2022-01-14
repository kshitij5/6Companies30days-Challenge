// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // similar question of max element at right
    // using stack pop-ans-push method
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        stack<int> st;
        vector<int> peak(n);

        // last element has no peak element
        st.push(n - 1);
        peak[n - 1] = n;

        for (int i = n - 2; i >= 0; i--) {
            // pop
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            //ans
            if (!st.empty()) peak[i] = st.top();
            else peak[i] = n;

            // push
            st.push(i);
        }

        int j = 0;
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            j = i;
            while (peak[j] < i + k) {
                j = peak[j];
            }

            res.push_back(arr[j]);
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends