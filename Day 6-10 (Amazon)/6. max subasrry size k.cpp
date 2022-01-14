// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    // using maximum element in right (pop-ans-push method)
    vector <int> max_of_subarrays(int* arr, int n, int k) {
        vector<int> peak(n);
        stack<int> st;

        st.push(n - 1);
        peak[n - 1] = n;
        // we first find the peak element of each curr elemnet
        for (int i = n - 2; i >= 0; i--) {
            // pop
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // ans
            if (!st.empty()) peak[i] = st.top();
            //  we take unexisting peak as n because in future we would need
            //  to see if the peak element exist after the window
            // -1 would not help in that case
            else peak[i] = n;

            //push
            st.push(i);
        }

        int j = 0;
        vector<int> res;
        // next we need to find such element which has its next greater element 
        // out of the window
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

        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution ob;
        vector <int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }

    return 0;
}  // } Driver Code Ends