#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个非负整数数组 nums 和一个整数 target 。
    - 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
    - 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
    - 返回可以通过上述方法构造的、运算结果等于 target 的不同表达式的数目。
*/

/*
    解题思路：
    - dp[i][j]: 数组中索引在i之前的数能够满足和为j的不同表达式的数目，这边数字即为商品，和其值即为重量或价值
    - 若对于所有数组有p个前面为正好，q个前面为负号
    - sum(nums[p]) + sum(nums[q]) = target;
    - sum(nums[p]) - sum(nums[q]) = sum(nums[p + q]);
    - sum(nums[p]) = (target + sum(nums[p + q]))/2; 此时就是一个背包问题了
    - dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
    - 初始化dp[0][j] = 1 if nums[0] == j else 0, 
    - 初始化dp[i][0] = 1
    - 迭代顺序，对于动态数组应当从右至左初始化
*/

int LeetCode::Solution494::findTargetSumWays(std::vector<int>& nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];

    if ((target + sum) % 2 != 0 || (target + sum)/2 > sum) return 0; // 当新target大于sum后，显然无解，不要忘了 
    target = (target + sum) / 2;
    if (target > sum || target < 0) return 0; // 添加负号检查

    std::vector<int> dp(target+1, 0);
    dp[0] = 1;
    for (int j = 0; j < dp.size(); j++) {
        if (nums[0] == j) dp[j] += 1;
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }
    return dp[target];
}
