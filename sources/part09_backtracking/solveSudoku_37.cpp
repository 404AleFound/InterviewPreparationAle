#include "part09_backtracking.h"


/**
 * 
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需 遵循如下规则：
 * 1. 数字 1-9 在每一行只能出现一次
 * 2. 数字 1-9 在每一列只能出现一次
 * 3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 */




bool LeetCode::Solution37::backtracking(std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') continue;
            for (int val = '1'; val <= '9'; val++) {
                if (!isvalid(row, col, val, board)) continue;
                board[row][col] = char(val);
                if (backtracking(board)) return true;
                board[row][col] = '.';
            }
            return false;
        }
    }
    return true;
}

bool LeetCode::Solution37::isvalid(int row, int col, char val, std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i == row) continue;
        if (board[i][col] == val) return false;
    }
    for (int j = 0; j < 9; j++) {
        if (j == col) continue;
        if (board[row][j] == val) return false;
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    int end_row = start_row + 3;
    int end_col = start_col + 3;
    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            if (board[i][j] == val) return false;
        }
    }
    return true;
    }

void LeetCode::Solution37::solveSudoku(std::vector<std::vector<char>>& board) {
    backtracking(board);
}