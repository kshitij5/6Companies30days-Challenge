#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

class Solution {
public:
    // using map
    // tc - o(n)
    // sc - o(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        // store anagrams in group using map
        for (auto& s : strs) {
            string key = s;

            // sorting to generate key
            sort(key.begin(), key.end());

            map[key].push_back(move(s));
        }

        vector<vector<string>> res;

        // extract all the grouped anagrams
        for (auto& it : map) res.push_back(move(it.second));

        return res;
    }
};