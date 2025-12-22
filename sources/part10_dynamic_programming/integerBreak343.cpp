#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给定一个正整数n，将其拆分为k个正整数的和（ k >= 2 ），并使这些整数的乘积最大化。
    - 返回你可以获得的最大乘积 。
*/

/*
    解题思路：
    - dp[i]i拆分后的最大乘积
    - dp[i] = std::max(j * dp[i - j]) for j = 1 to j = i - 1
    - dp[0] = ?, dp[1] = 1, dp[2] = max(1 * dp[1], dp[1] * 1) = 1
    - 双层遍历，第一层从i=3开始，第二层从j=1开始
*/
int LeetCode::Solution343::integerBreak(int n) {
    std::vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i-1; j++) {
            dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}