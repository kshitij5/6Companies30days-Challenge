#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

class Solution {
public:
    // brute force
//     string decodeString(string s) {
//         stack<char> st;
//         int n = s.size();
//         string res;
//         for(int i=0;i<n;i++) {
//             if(s[i] == ']') {
//                 string newst = "";

//                 while(true) {
//                     char c = st.top();
//                     if(c=='[') {
//                         st.pop();
//                         break;
//                     }

//                     newst = c + newst;
//                     st.pop();
//                 }
//                 int num = 0;
//                 string numtemp="";
//                 while(!st.empty()) {
//                     if(!isdigit(st.top())) break;
//                     numtemp = st.top()+numtemp;
//                     st.pop();
//                 }

//                 for(char c: numtemp)
//                     num = num*10 + c - '0';

//                 string str;
//                 while(num--) str += newst;

//                 for(char c: str) st.push(c);
//             }
//             else
//                 st.push(s[i]);
//         }

//         while(!st.empty()) {
//             res=st.top()+res;
//             st.pop();
//         }
//         return res;
//     }
    // using stack
    // tc - o(N)
    // sc - o(N)

    string repeat(string& s, int times) {
        for (int n = s.size(); --times; s += s.substr(0, n));
        return s;
    }
    string decodeString(string& s) {
        // {n, ans} = {count to repeat, string formed in this level till now}
        stack<pair<string, string>> stk;
        string ans = "", n = "";
        for (auto c : s)
            if (isalpha(c))      ans += c;
            else if (isdigit(c)) n += c;
        // push the n, ans into stack once we start new word
        // move automatically clears n, ans instead of copying also aiding tc
            else if (c == '[')   stk.push({ move(n), move(ans) });
            else {
                auto it = stk.top(); stk.pop();
                ans = it.second + repeat(ans, stoi(it.first));
            }

        return ans;
    }
};