#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
    - 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
    - 如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

/*
    解题思路：
    - 
*/

int LeetCode::Solution300::lengthOfLIS(std::vector<int>& nums){
    int len = nums.size();
    if (len <= 1) return len;
    std::vector<int> dp(len, 1);
    int res = 0;
    for (int i = 1; i < len; i++){
        for (int j = 0; j < i; j++){
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        res = std::max(res, dp[i]);
    }
    return res;
}
