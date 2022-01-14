// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    string colName(long long int n)
    {
        string res = "";

        while (n) {
            n--;
            // why n--? visit ----> https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC%2B%2B)
            char c = (n % 26) + 'A';
            res = c + res;
            n /= 26;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n; cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}
// } Driver Code Ends