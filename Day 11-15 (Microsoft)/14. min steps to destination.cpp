// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // constructive alogithm
    // the basic idea is to keep adding numbers until either 
    // we reach our target or greater than it
    // in case of greater we have to look for if (sum-target)%2 == 0
    // why? when we check %2, we are checking will we reach out target 
    // if we subract 2*i places back? in other word we are trying to find
    // steps that will be equal to the currsum minus target
    int minSteps(int D) {
        int steps = 0, sum = 0;

        while (true) {
            sum = sum + steps;
            steps++;
            if (sum == D) {
                return steps - 1;
                break;
            }
            if (sum > D and (sum - D) % 2 == 0) {
                return steps - 1;
                break;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
}  // } Driver Code Ends