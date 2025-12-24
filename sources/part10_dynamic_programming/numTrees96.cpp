#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数n，求恰由n个节点组成且节点值从1到n互不相同的二叉搜索树有多少种？
    - 返回满足题意的二叉搜索树的种数。
*/

/*
    解题思路：
    - dp[i]:由i个节点组成且节点值从1到i互不相同的二叉搜索树有dp[i]种
    - dp[i] += dp[j - 1] * dp[i - j];
    - 例如：dp[3]=dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0];
    - dp[0] = 1;
    - 从头到尾依次循环即可
*/

int LeetCode::Solution96::numTrees(int n) {
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}