// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    /*You are required to complete this method */
    int atoi(string str) {
        int n = str.size();
        int res = 0, check = 0;

        if (str[0] == '-') check = 1;

        for (int i = check; i < n; i++) {
            if (isalpha(str[i])) {
                return -1;
            }
            res = res * 10 + (str[i] - '0');
        }

        if (check) return -res;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}  // } Driver Code Ends