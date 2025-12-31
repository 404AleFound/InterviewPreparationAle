#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 你是一个专业的小偷，计划偷窃沿街的房屋。
    - 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
    - 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    - 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/


int LeetCode::Solution213::robrange(const std::vector<int>& nums, int start, int end){
    if (end - start == 0) return nums[start];
    std::vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    dp[start + 1] = std::max(nums[start], nums[start + 1]);
    for (int i = start+2; i <= end; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[end];
}
int LeetCode::Solution213::rob(std::vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];
    int a = robrange(nums, 1, len - 1);
    int b = robrange(nums, 0, len - 2);
    return std::max(a, b);
}