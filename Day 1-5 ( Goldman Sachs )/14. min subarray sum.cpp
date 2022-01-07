#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

class Solution {
public:
    // using sliding window
    // tc - O(n)
    // sc - O(n)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0, m = INT_MAX;

        while (left < n) {
            if (sum >= target) {
                m = min(m, right - left);
                sum -= nums[left++];

            }
            else if (sum < target) {
                if (right >= n) break;
                sum += nums[right++];
            }
        }

        return (m == INT_MAX) ? 0 : m;
    }
};