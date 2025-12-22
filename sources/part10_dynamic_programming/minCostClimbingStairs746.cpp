#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数数组cost。
    - 其中cost[i]是从楼梯第i个台阶向上爬需要支付的费用。
    - 一旦你支付此费用，即可选择向上爬一个或者两个台阶。
    - 请你计算并返回达到楼梯顶部的最低花费。
*/

/*
    解题思路：
    - dp[i]：爬到i阶需要的最低花费
    - dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
    - dp[0] = 0, dp[1] = 0, dp[2] = 0
    - 遍历顺序，从前向后遍历即可，从第三个台阶也就是i=2开始遍历
*/
int LeetCode::Solution746::minCostClimbingStairs(std::vector<int>& cost) {
    if (cost.size() <= 2) return 0;
    int dp1 = 0;
    int dp2 = 0;
    for (int i = 2; i <= cost.size(); i++) {
        int next = std::min(dp1+cost[i-2], dp2+cost[i-1]);
        dp1 = dp2;
        dp2 = next;
    }
    return dp2;
}
