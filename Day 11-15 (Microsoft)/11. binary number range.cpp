// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
// using bfs technique
// tc - o(n)
// sc - o(n)
vector<string> generate(int N)
{
    vector<string> res;

    queue<string> q;
    q.push("1");

    while (res.size() < N) {
        string base = q.front();
        q.pop();

        res.push_back(base);
        q.push(base + "0");
        q.push(base + "1");
    }

    return res;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends