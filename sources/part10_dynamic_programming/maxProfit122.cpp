#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
    - 在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。
    - 然而，你可以在同一天多次买卖该股票，但要确保你持有的股票不超过一股。
    - 返回你能获得的最大利润 。
*/

/*
    解题思路：
    - dp[i][0] = 第i天持有股票所得最多现金
    - dp[i][1] = 第i天不持有股票所得最多现金
    - dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]-prices[i]);
    - dp[i][1] = std::max(dp[i-1][0] + prices[i], dp[i-1][1]);
*/

int LeetCode::Solution122::maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = std::max(dp[i-1][0] + prices[i], dp[i-1][1]);
    }
    return std::max(dp[len-1][0], dp[len-1][1]);
}