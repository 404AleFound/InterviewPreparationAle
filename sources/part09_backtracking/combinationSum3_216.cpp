#include "part09_backtracking.h"

/**
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *  - 只使用数字1到9
 *  - 每个数字最多使用一次 
 * 返回所有可能的有效组合的列表。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

void LeetCode::Solution216::backtracking(int k, int n, int startIndex) {
    if (path.size() == k) {
        if (sum == n) res.push_back(path);
        return;
    }
    for (int i = startIndex; 9 - i + 1 >= k - path.size(); i++) {
        sum += i;
        path.push_back(i);
        backtracking(k, n, i + 1);
        path.pop_back();
        sum -= i;
    }
}
std::vector<std::vector<int>> LeetCode::Solution216::combinationSum3(int k, int n) {
    backtracking(k, n, 1);
    return res;
}
