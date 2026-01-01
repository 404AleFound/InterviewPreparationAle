#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
    - 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
    - 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*
    解题思路：
    - 无非把4中状态换为k种状态
*/

int LeetCode::Solution188::maxProfit(int k, std::vector<int>& prices){
    int len = prices.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(2 * k, 0));
    for(int i = 0; i < 2 * k; i++) {
        if(i % 2 == 0) dp[0][i] = -prices[0];
    }

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < 2 * k; j++) {
            if (j == 0) {
                dp[i][j] = std::max(-prices[i], dp[i-1][0]);
            } else if (j % 2 == 0) { // 偶数，买入
                dp[i][j] = std::max(dp[i-1][j-1] - prices[i], dp[i-1][j]);
            } else if (j % 2 != 0) { // 奇数，卖出
                dp[i][j] = std::max(dp[i-1][j-1] + prices[i], dp[i-1][j]);
            }
        }
    }

    return dp[len - 1][2 * k - 1];
}