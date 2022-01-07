// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // the basic idea is to hypothesize that the rectangles never overlap
        // and if its not true, we return true else false

        // rectangles can never overlap if :
        // one rectangle is on left side of other
        if (l1[0] > r2[0] || l2[0] > r1[0])
            return false;

        //one rectangle is above other
        if (r1[1] > l2[1] || r2[1] > l1[1])
            return false;

        // else our hypothesis is wrong and rectangles indeed overlapp
        return true;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends