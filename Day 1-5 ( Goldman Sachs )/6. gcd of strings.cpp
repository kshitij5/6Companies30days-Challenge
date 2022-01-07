#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

class Solution {
public:
    // brute force
    string gcdOfStrings(string str1, string str2) {
        // handling special case
        // note: gcd = 1 for strings is possible ,
        // only if all the characters of str1 and str2 are same
        // gcd of two string (>1) is only possible if a+b = b+a
        if (str1 + str2 != str2 + str1)
            return "";

        return (str1.substr(0, __gcd(str1.size(), str2.size())));
        // if gcd possible, we find the gcd of length and returns it
    }
};