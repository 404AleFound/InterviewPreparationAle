#include "part09_backtracking.h"

/**
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * Input: nums = [1,1,2]
 * Output: [[1,1,2],[1,2,1],[2,1,1]]
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */
 void LeetCode::Solution47::backtracking(const std::vector<int>& nums, std::vector<bool>& used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false || used[i] == true)
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        used[i] = false;
        path.pop_back();
    }
}
std::vector<std::vector<int>> LeetCode::Solution47::permuteUnique(std::vector<int>& nums) {
    std::vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return res;
}