#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给定一个整数数组prices，其中第 prices[i] 表示第 i 天的股票价格。​
    - 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
    - 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
    - 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*
    解题思路：
    - 设定四种状态：持有股票0，不持有股票（当天卖出1，处于冷冻期2，不处于冷冻期3）
    - 分别为0，1，2，3
    - dp[j][0] = std::max(dp[j-1][0], dp[j-1][2] - prices[i], dp[j-1][3] - prices[i]); 
    - dp[j][1] = std::max(dp[j-1][0] + prices[i])
    - dp[j][2] = std::max(dp[j-1][1])
    - dp[j][3] = std::max(dp[j-1][2], dp[j-1][3])
    - 关键是正确书写状态传递的关系
*/

int LeetCode::Solution309::maxProfit(std::vector<int>& prices){
    int len = prices.size();
    if (len == 0) return 0;
    std::vector<std::vector<int>> dp(len, std::vector<int>(4,0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i-1][0], std::max(dp[i-1][2]-prices[i], dp[i-1][3]-prices[i]));
        dp[i][1] = dp[i-1][0]+prices[i];
        dp[i][2] = dp[i-1][1];
        dp[i][3] = std::max(dp[i-1][2], dp[i-1][3]);
    }
    return std::max(dp[len-1][1], std::max(dp[len-1][2], dp[len-1][3]));
}
