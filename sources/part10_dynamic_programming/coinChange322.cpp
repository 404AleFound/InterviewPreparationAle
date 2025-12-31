#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
    - 请你从 nums 中找出并返回总和为 target 的元素组合的个数。
    -题目数据保证答案符合 32 位整数范围。
*/

/*
    解题思路：
*/

int LeetCode::Solution322::coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = std::min(dp[j], dp[j-coins[i]] + 1);
            } 
        }
    }
    return dp[amount] != INT_MAX ? dp[amount] : -1;
}