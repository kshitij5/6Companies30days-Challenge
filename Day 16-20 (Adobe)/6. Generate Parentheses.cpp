// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    // advanced recursion and backtracking
    vector<string> res;
    vector<string> AllParenthesis(int n)
    {
        string s;
        helper(s, n, n);
        return res;
    }

    // helper function
    void helper(string& s, int open, int close) {
        // base condition
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }

        // condition to push opening bracket
        // is if there is open bracket left
        if (open > 0) {
            s.push_back('(');
            // recursion
            helper(s, open - 1, close);
            // backtracking
            s.pop_back();
        }

        // condition to push an closing bracket
        // is only when string contains more opening than closing
        // and if closing bracket is left
        if (close > 0 && close > open) {
            s.push_back(')');
            // recursion
            helper(s, open, close - 1);
            //backtracking
            s.pop_back();
        }

        return;
    }


};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends