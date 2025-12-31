#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 你是一名宇航员，即将前往一个遥远的行星。
    - 在这个行星上，有许多不同类型的矿石资源，每种矿石都有不同的重要性和价值。
    - 你需要选择哪些矿石带回地球，但你的宇航舱有一定的容量限制。 
    - 给定一个宇航舱，最大容量为 C。现在有 N 种不同类型的矿石，每种矿石有一个重量 w[i]，一个价值 v[i]，以及最多 k[i] 个可用。
    - 不同类型的矿石在地球上的市场价值不同。
    - 你需要计算如何在不超过宇航舱容量的情况下，最大化你所能获取的总价值。

    解题思路：
    - 在添加一个循环对商品数目进行迭代即可。
*/

int LeetCode::SolutionMulbp::multiBackpack(int bagweight, std::vector<int> values, 
                                        std::vector<int> weights, std::vector<int> nums) {
    std::vector<int> dp(bagweight + 1, 0);

    for (int i = 0; i < values.size(); i++) {
        for (int j = bagweight; j >= weights[i]; j--) {
            for (int k = 1; k <= nums[i] && j >= k * weights[i]; k++) {
                dp[j] = std::max(dp[j], dp[j - k * weights[i]] + k * values[i]);
            }
        }
    }
    return dp[bagweight];
}

