#include "part09_backtracking.h"

/**
 * 给你一个整数数组 nums，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 解集不能包含重复的子集。返回的解集中，子集可以按任意顺序排列。
 * 
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 */

void LeetCode::Solution90::backtracking(const std::vector<int>& nums, int index, std::vector<bool>& used) {
       for (int i = index; i < nums.size(); i++) {
           if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
               continue;
           }
           path.push_back(nums[i]);
           res.push_back(path);
           used[i] = true;
           backtracking(nums, i + 1, used);
           used[i] = false;
           path.pop_back();
       }
   }

std::vector<std::vector<int>> LeetCode::Solution90::subsetsWithDup(std::vector<int>& nums) {
        res.push_back(path);
        sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return res;
    }