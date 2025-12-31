#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i]。
    - 每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。
*/

/*
    解题思路：
    - 基本和01背包相同
    - 对于一维滑动数组中背包的遍历必须从左到右进行遍历。
*/

int LeetCode::Solutionfullbp::fullBackpack(int bagweight, std::vector<int> values, std::vector<int> weights) {
    std::vector<int> dp(bagweight+1, 0);

    for (int i = 0; i < values.size(); i++){
        for (int j = 0; j <= bagweight; j++) {
            if (j - weights[i] >= 0) dp[j] = std::max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }
    return dp[bagweight];
}