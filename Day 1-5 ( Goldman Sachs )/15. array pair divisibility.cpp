// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        // if length is odd
        if (nums.size() & 1) return false;

        unordered_map<int, int>m;

        //store the count of remainders in a map.
        for (auto x : nums) m[(x % k + k) % k]++;

        for (auto x : nums) {
            int rem = (x % k + k) % k;
            //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            if (rem == 0) {
                //if count of numbers that give this remainder is odd all pairs can't be made hence return false.
                if (m[rem] & 1) return false;
            }
            //if the remainder rem and k-rem do not have the same count then pairs can not be made 
            else if (m[rem] != m[k - rem]) return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends