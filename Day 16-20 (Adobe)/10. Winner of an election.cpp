// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:

    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
        }

        string res; int max = INT_MIN;
        for (auto it : map) {
            if (it.second > max) {
                max = it.second;
                res = it.first;
            }
            else if (it.second == max && it.first.compare(res) < 0) {
                res = it.first;
            }
        }

        return { res, to_string(max) };
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    for (int i = 0;i < t;i++)
    {


        int n;
        cin >> n;

        string arr[n];

        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
// } Driver Code Ends