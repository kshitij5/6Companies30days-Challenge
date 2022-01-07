// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main() {

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{
    int count = 0;
    char curr = src[0];
    string newstr = "";

    for (char c : src) {
        if (c != curr) {
            newstr += (curr + to_string(count));
            curr = c;
            count = 0;
        }
        count++;
    }
    newstr += (curr + to_string(count));
    return newstr;
}

