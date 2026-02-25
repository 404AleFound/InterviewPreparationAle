#include<iostream>
#include<vector>

using namespace std;

/**
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 */


class Solution {
private:
    vector<vector<string>> res;
    bool canUse(int row, int col, const vector<string>& chessboard) {
        int n = chessboard.size();
        for(int i = 0; i < n; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }

        for (int j = 0; j < n; j++) {
            if (chessboard[row][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtracking(int n, int numRow, vector<string>& chessboard) {
        if (numRow == n) {
            res.push_back(chessboard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!canUse(numRow, i, chessboard)) continue;
            chessboard[numRow][i] = 'Q';
            numRow++;
            backtracking(n, numRow, chessboard);
            numRow--;
            chessboard[numRow][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);
    cout << "The answer of solveNQueen_51 is: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "Answer " << i << ": " << endl;
        for (int j = 0; j < n; j++) {
            string format;
            format.resize(n * 2);
            for (int k = 0; k < format.size(); k++) {
                if (k % 2 == 0) format[k] = ans[i][j][k / 2];
                else format[k] = '\t';                  
            }
            cout << format << endl;
        }
    }
}