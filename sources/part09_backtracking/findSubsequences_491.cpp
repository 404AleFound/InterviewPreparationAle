#include "part09_backtracking.h"

/**
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。
 * 你可以按 任意顺序 返回答案。
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * Input: nums = [4,6,7,7]
 * Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * Input: nums = [4,4,3,2,1]
 * Output: [[4,4]]
 */

void LeetCode::Solution491::backtracking(const std::vector<int>& nums, int index) {
    if (path.size() >= 2) res.push_back(path);
    std::unordered_set<int> uset;
    for(int i = index; i < nums.size(); i++) {
        if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
            continue;
        }
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> LeetCode::Solution491::findSubsequences(std::vector<int>& nums) {
    backtracking(nums, 0);
    return res;
}