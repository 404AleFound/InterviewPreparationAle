#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
    - 设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。
    - 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*
    解题思路：
    - 第一次持有：  dp[i][0] = max(-prices[i], dp[i-1][1]);
    - 第一次卖出：  dp[i][1] = max(dp[i-1][1] + prices[i], dp[i-1][2]);
    - 第二次持有：  dp[i][2] = max(dp[i-1][2] - prices[i], dp[i-1][3]);
    - 第二次卖出：  dp[i][3] = max(dp[i-1][3] + prices[i], dp[i-1][4]);
*/

int LeetCode::Solution123::maxProfit(std::vector<int>& prices){
    int len = prices.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(4, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = -prices[0];
    dp[0][3] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(-prices[i], dp[i-1][0]);
        dp[i][1] = std::max(dp[i-1][0] + prices[i], dp[i-1][1]);
        dp[i][2] = std::max(dp[i-1][1] - prices[i], dp[i-1][2]);
        dp[i][3] = std::max(dp[i-1][2] + prices[i], dp[i-1][3]);
    }

    return dp[len-1][3];
}