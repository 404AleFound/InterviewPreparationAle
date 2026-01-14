#include "part09_backtracking.h"


/**
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 */

void LeetCode::Solution78::backtracking(const std::vector<int>& nums, int index) {
    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        res.push_back(path);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> LeetCode::Solution78::subsets(std::vector<int>& nums) {
    res.push_back(path);
    backtracking(nums, 0);
    return res;
}
