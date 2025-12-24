#include "part10_dynamic_programming.h"

/*
    题目描述：
    -有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
    - 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
    - 如果 x == y，那么两块石头都会被完全粉碎； 
    - 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
    - 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
*/

/*
    解题思路：
    - 转化为分割等和子集
    - return sum - 2 * dp[sum/2]
*/

int LeetCode::Solution1049::lastStoneWeightII(std::vector<int>& stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); i++) sum += stones[i];
    std::vector<int> dp(sum / 2 + 1, 0);

    // for (int j = 0; j <= sum / 2; j++) dp[j] = stones[0] <= j ? stones[0] : 0;
    // 这边这行初始化是多余的，在i=0进行遍历时，会自动完成上述初始化过程
    // 遍历背包容量时，是从右往左遍历

    for (int i = 0; i < stones.size(); i++) {
        for (int j = sum/2; j >= stones[i]; j--) {
            dp[j] = std::max(dp[j], stones[i] + dp[j - stones[i]]);
        }
    }

    return sum - 2 * dp[sum / 2];
} 