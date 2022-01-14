// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    void matchPairs(char nuts[], char bolts[], int n) {
        for (int i = 0; i < n; i++) {
            //O(n^2) approach , we cannot compare bolts and bolts as well as nuts and nuts
            //elese we could have just sorted the two arrays
            char curr_nut = nuts[i];
            for (int j = i; j < n; j++) {
                if (bolts[j] == curr_nut) {
                    //swap bolt[i] & bolt[j]
                    int temp = bolts[i];
                    bolts[i] = bolts[j];
                    bolts[j] = temp;
                    break;
                }
            }
        }
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends