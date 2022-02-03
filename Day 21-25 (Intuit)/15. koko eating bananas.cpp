class Solution {
public:
    // using binary search
    // tc - o(log n)
    // sc - o(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            // for k bananas/hr speed
            k = (low + high) / 2;

            // findind if the time required to finish all the piles
            int time = 0;
            for (int i = 0; i < piles.size(); i++)
                time += ceil(1.0 * piles[i] / k);

            // is within the given h hours
            // if not we speed up the eating speed
            if (time > h)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;
    }
};