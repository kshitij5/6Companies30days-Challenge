#include <bits/stdc++.h>
using namespace std;

// n ==> Size of circle
// m ==> Number of items
// k ==> Initial position

// using brute force
// tc- o(1)
// sc - o(1)
int lastPosition(int n, int m, int k) {
    // initially, n - k + 1 is number of positions
    // before we reach beginning of circle

    // since we are distributing toys from kth position,
    // we have to find if the toys ends before the last 
    // kid's position (n - k + 1)
    // in that case, we can simply return (m-1)th position
    if (m <= (n - k + 1))
        return m + k - 1;

    // then we compute remaining items before
    // we reach beginning.
    m = m - (n - k + 1);

    // if items are still left, we will compute m % n 
    // to skip all complete rounds and when we reach end
    //  we return n
    return (m % n == 0) ? n : (m % n);
}
