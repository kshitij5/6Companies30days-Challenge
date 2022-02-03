class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), minswap = 0;

        vector<int> rows;

        // first step would be to count the trailing zeroes
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            rows.push_back(count);
        }

        for (int i : rows) cout << i << " ";

        // since we need to have zeroes above the diagonal, we will swap as per the trailer zeroes
        // thus the problem now becomes sorting problem with min swaps

        for (int i = 0; i < n; i++) {
            int k = i;
            int req = n - 1 - i; // desired tailing zero count

            while (k < n && rows[k] < req) k++; // greedily find first swaping candidate and log the result into k.

            if (k == n) return -1; // k is out of range. Fail in searching

            //Part 1: move k-th row up to i-th row
            minswap += (k - i); // accumulate the operation cost of moving k to i

            //Part 2: move the rest involved row downward by offset 1
            while (k > i) { // simulate swaping operation of two adjacent rows in range of [i, k-1 ]
                rows[k] = rows[k - 1];
                k--;
            }
        }

        return minswap;
    }
};