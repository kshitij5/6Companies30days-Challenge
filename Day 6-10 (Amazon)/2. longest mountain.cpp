class Solution {
public:
    // using peak and valley method
    // tc - o(n)
    // sc - o(n)
    int longestMountain(vector<int>& arr) {
        int n = arr.size() - 1;
        if (n < 2) return 0;

        int res = 0, i = 0, peak = 0, valley = 0;
        while (i < n) {
            // we have to first find the peak
            if (arr[i] < arr[i + 1]) {
                int start = i;

                // after finding the first peak, all we have to do is to increase
                // till we find the fall
                while (i < n && arr[i] < arr[i + 1]) {
                    i++;
                    peak = 1;
                }

                // then we have to find the valley where another peak starts
                while (i < n && arr[i] > arr[i + 1]) {
                    i++;
                    valley = 1;
                }

                // we found a mountain only when we find both peak and valley points
                if (peak && valley) {
                    res = max(res, i - start + 1);
                }

                // reset peak and valley value
                peak = 0;
                valley = 0;
            }
            else {
                // else we just increment the ith pos
                i++;
            }
        }

        return res;
    }
};