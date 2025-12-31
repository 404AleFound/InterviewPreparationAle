#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
    - 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
    - 例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/

/*
    解题思路：
*/

int LeetCode::Solution279::numSquares(int n) {
    std::vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i*i <= n; i++) {
        for (int j = i*i; j <= n; j++) {
            if (dp[j - i*i] != INT_MAX) 
                dp[j] = std::min(dp[j], dp[j-i*i] + 1);
        }
    }
    return dp[n] != INT_MAX ? dp[n] : -1;
}