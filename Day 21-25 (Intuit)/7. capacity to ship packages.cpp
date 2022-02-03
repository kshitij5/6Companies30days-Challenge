class Solution {
public:
    // using binary search
    // tc - o(logn)
    // sc - o(1)

    int isPossible(vector<int>& nums, int m, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > mid) {
                sum = nums[i];
                m--;
            }
        }
        return m > 0;
    }

    // the trick here is do the binary search search for finding the min largest sum
    int shipWithinDays(vector<int>& weights, int days) {
        // so the min largest value we can have is the max value in arr
        // why ? even if we have m = srr.size(), min largest sum will be max element

        // same way max min largest will be sum of element, why ? if m = 0, then?
        int l = 0, r = 0, ans = 0;

        for (int i : weights) {
            l = max(l, i);
            r += i;
        }

        // we got the rang l - r
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // we  have to find if the largest sum = mid, can we split nums into m parts
            if (isPossible(weights, days, mid)) {
                // if possible then we will try finding smaller min largest possible
                ans = mid;
                r = mid - 1;
            }
            else {
                // else we will try increasing min largest
                l = mid + 1;
            }
        }

        return ans;
    }
};