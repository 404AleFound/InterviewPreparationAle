#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    - 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。
    - 设计一个算法来计算你所能获取的最大利润。
    - 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

/*
    解题思路：
    - dp[i][0] = 第i天持有股票所得最多现金
    - dp[i][1] = 第i天不持有股票所得最多现金
    - dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]-price(i));
    - dp[i][1] = std::max(dp[i-1][0] + price[i], dp[i-1][1]);
*/

int LeetCode::Solution121::maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i-1][0], -prices[i]);
        dp[i][1] = std::max(dp[i-1][0] + prices[i], dp[i-1][1]);
    }
    return dp[len-1][1];
}