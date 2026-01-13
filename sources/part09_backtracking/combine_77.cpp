#include "part09_backtracking.h"

/**
 *  给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *  你可以按任何顺序返回答案。
 *
 *  Input: n = 4, k = 2
 *  Output: [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
 * 
 *  Input: n = 1, k = 1
 *  Output: [[1]]
 */

void LeetCode::Solution77::backtracking(int n, int k, int startIndex) {
    if(path.size() == k) {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; n - i + 1 >= k - path.size(); i++) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> LeetCode::Solution77::combine(int n, int k) {
    backtracking(n, k, 1);
    return res;
}