// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        //first remove dulpicate and sort the contacts
        set<string> newContacts;
        for (int i = 0; i < n; i++) {
            newContacts.insert(contact[i]);
        }

        vector<vector<string>> res;
        string prefix;

        for (int i = 0; i < s.size(); i++) {
            vector<string> ans;
            for (string contact : newContacts) {
                if (s.substr(0, i + 1) == contact.substr(0, i + 1)) {
                    ans.push_back(contact);
                }
            }
            if (ans.size() > 0) res.push_back(ans);
            else res.push_back({ "0" });
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0;i < n;i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0;i < s.size();i++) {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends