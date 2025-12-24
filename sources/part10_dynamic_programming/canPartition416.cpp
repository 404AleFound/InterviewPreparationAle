#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个只包含正整数的非空数组nums。
    - 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/

/*
    解题思路
    - 本题要求就是集合里能否出现总和为 sum / 2 的子集
    - 背包容量就是nums.size(), 商品的value、weight均为元素的值
    - dp[i]：当背包容量为i时所能装下的最大价值
*/

bool LeetCode::Solution416::canPartition(std::vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum % 2 != 0) return false;

    std::vector<int> dp(sum/2+1, 0);    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = sum/2; j >= nums[i]; j--) {
            dp[j] = std::max(dp[j], nums[i] + dp[j - nums[i]]);
        }
    }

    if (dp[sum/2] == sum/2) return true;
    else return false;
}