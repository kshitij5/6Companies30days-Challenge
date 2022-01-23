// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution {
public:

    // custom class for storing element  datas
    class element {
    public:
        int val, index, row;
        element(int val, int index, int row) {
            this->val = val;
            this->index = index;
            this->row = row;
        }
    };

    struct compare {
        bool operator()(element a, element b) {
            return a.val > b.val;
        }
    };

    // using heap
    pair<int, int> findSmallestRange(int arr[][N], int n, int k) {
        priority_queue<element, vector<element>, compare> hp;
        int mn = INT_MIN, mx = INT_MIN, range = INT_MAX;

        // step 1 : we need to store first index of each list into heap
        // and also store the min range in this case
        for (int i = 0; i < k; i++) {
            hp.push(element(arr[i][0], 0, i));

            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i][0]);
        }

        int low = mn, high = mx;
        // step 2 : next we need to traverse list where index is min
        // trying to find the minimum range
        while (!hp.empty()) {
            element top = hp.top();
            hp.pop();

            int maybemin = top.val;

            // if we get a smaller range
            if (range > (mx - maybemin)) {
                // update values
                mn = maybemin;
                range = mx - maybemin;
                low = mn;
                high = mx;
            }

            // if we reach the end of any list
            if (top.index == n - 1) {
                break;
            }

            top.index += 1;
            // push next adjacent element to heap
            hp.push(element(arr[top.row][top.index], top.index, top.row));
            mx = max(mx, arr[top.row][top.index]);
        }

        return make_pair(low, high);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends