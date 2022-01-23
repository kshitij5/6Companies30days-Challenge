#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

signed main() {
    //    ios::sync_with_stdio(0);
    //   cin.tie(0); cout.tie(0);

    int t;  //no of test cases
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int size1 = a.size();
        int size2 = b.size();

        if (size1 > size2) {
            cout << a << " is recent" << endl;
        }
        else {
            cout << b << " is recent" << endl;
        }

        for (int i = 0; i < size1; i++) {
            int x = a[i] - '0', y = b[i] - '0';
            int val = x - y;
            if (val > 0) {
                cout << a << " is recent" << endl;
            }
            else if (val < 0) {
                cout << b << " is recent" << endl;
            }
        }
    }
    return 0;
}