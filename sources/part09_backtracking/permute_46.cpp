#include "part09_backtracking.h"

/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * 
 * Input: nums = [1]
 * Oytput: [[1]]
 */

void LeetCode::Solution46::backtracking(const std::vector<int>& nums, std::vector<bool>& used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if (used[i] == true)
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        used[i] = false;
        path.pop_back();
    }
}

    
std::vector<std::vector<int>> LeetCode::Solution46::permute(std::vector<int>& nums) {
    std::vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}