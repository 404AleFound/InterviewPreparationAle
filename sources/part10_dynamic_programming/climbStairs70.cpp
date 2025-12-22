#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 假设你正在爬楼梯，需要n阶你才能到达楼顶。
    - 每次你可以爬1或2个台阶。
    - 你有多少种不同的方法可以爬到楼顶呢？
*/

/*
    解题思路：
    - 定义dp数组：dp[i]爬到i阶有n种方法
    - 定义递推关系：dp[i] = dp[i-1] + dp[i-2]
    - 初始化dp数组：dp[1] = 1, dp[2] = 2
    - 确定遍历顺序：依旧从前向后遍历即可，为节省空间可以只定义三个数组
*/\

int LeetCode::Solution70::climbStairs(int n) {
    if (n == 1 || n == 0) return n;
    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        int next = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = next;
    }
    return dp[2];
}
