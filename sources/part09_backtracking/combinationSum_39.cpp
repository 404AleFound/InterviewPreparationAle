#include "part09_backtracking.h"

/**
 * 给你一个无重复元素的整数数组 candidates 和一个目标整数 target ，
 * 找出 candidates 中可以使数字和为目标数 target 的所有不同组合 ，并以列表形式返回。你可以按任意顺序返回这些组合。
 * candidates 中的同一个 数字可以无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 */

void LeetCode::Solution39::backtracking(const std::vector<int>& candidates, int target, int index) {
       if (sum > target) {
           return;
       }
       if (sum == target) {
           res.push_back(path);
           return;
       }
       for (int i = index; i < candidates.size(); i++) {
           sum += candidates[i];
           path.push_back(candidates[i]);
           backtracking(candidates, target, i);
           path.pop_back();
           sum -= candidates[i];
       }
   }

std::vector<std::vector<int>> LeetCode::Solution39::combinationSum(std::vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }