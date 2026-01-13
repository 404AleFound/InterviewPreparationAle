#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
    - 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
    - 返回获得利润的最大值。
    - 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/

/*
    解题思路：
    - 统一在买入的时候扣除费用即可
*/

int LeetCode::Solution714::maxProfit(std::vector<int>& prices, int fee){
    int len = prices.size();
    if (len == 0) return 0;
    std::vector<std::vector<int>> dp(len, std::vector<int>(2,0));
    // 0 表示持有, 1表示不持有
    dp[0][0] = -prices[0] - fee;
    dp[0][1] = 0;
    for(int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] - prices[i] - fee);
        dp[i][1] = std::max(dp[i-1][0] + prices[i], dp[i-1][1]);
    }
    return std::max(dp[len-1][0], dp[len-1][1]);
}
