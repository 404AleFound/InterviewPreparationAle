#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
    - 每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
    - 注意：给定 n 是一个正整数。
*/

/*
    解题思路：
    - goods are 1, 2, 3, ..., m
    - the order is important
*/

int LeetCode::SolutionStair::climbStair(int m, int n){
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (j >= i) dp[j] = dp[j] + dp[j-i];
        }
    }
    return dp[n];
}
