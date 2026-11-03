class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            backtrack(row + 1, n);

            board[row][c] = '.';
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        board.assign(n, string(n, '.'));
        col.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);

        backtrack(0, n);

        return ans;
    }
};