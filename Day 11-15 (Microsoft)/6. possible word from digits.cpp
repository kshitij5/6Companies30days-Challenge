// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    string keypad[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> v;
        for (char c : keypad[a[N - 1]]) {
            string s(1, c);
            v.push_back(s);
        }

        return helper(a, v, N - 2);
    }

    vector<string> helper(int a[], vector<string> res, int i) {
        if (i < 0) return res;

        string curr_string = keypad[a[i]];

        vector<string> newres;
        for (char c : curr_string) {
            for (string s : res) {
                newres.push_back(c + s);
            }
        }

        return helper(a, newres, i - 1);
    }
};


// { Driver Code Starts.

int main() {

    int T;

    cin >> T; //testcases

    while (T--) { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0;i < N;i++) {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector <string> res = obj.possibleWords(a, N);
        for (string i : res) cout << i << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends