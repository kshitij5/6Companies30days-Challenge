// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    if (helper(i, j, board, 0, word))
                        return true;
                }
            }
        }

        return false;
    }

    bool helper(int i, int j, vector<vector<char>>& board, int next, string word) {
        if (next == word.size()) {
            // if such string exists
            return true;
        }

        // base case
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[next]) {
            return false;
        }


        char c = board[i][j];
        board[i][j] = '#';
        // else traverse 8-directionally
        bool exist = helper(i + 1, j, board, next + 1, word) ||
            helper(i - 1, j, board, next + 1, word) ||
            helper(i, j + 1, board, next + 1, word) ||
            helper(i, j - 1, board, next + 1, word);

        board[i][j] = c;

        return exist;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends