#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个由不同整数组成的数组 nums ，和一个目标整数 target。
    - 请你从 nums 中找出并返回总和为 target 的元素组合的个数。
    - 题目数据保证答案符合 32 位整数范围。
*/

/*
    解题思路
*/

int LeetCode::Solution377::combinationSum4(std::vector<int>& nums, int target){
    std::vector<uint64_t> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= target; j++) {
        for (int i = 0; i < nums.size(); i++) {
            if (j - nums[i] >= 0) dp[j] = dp[j] + dp[j-nums[i]];
        }
    }
    return dp[target];
}
