#include "part09_backtracking.h"

/**
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 注意：解集不能包含重复的组合。
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * Output: [[1,2,2],[5]]
 */

void LeetCode::Solution40::backtracking(const std::vector<int>& candidates, int target, int index, std::vector<bool> used) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size() && candidates[i] <= target - sum; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i-1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i+1, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

std::vector<std::vector<int>> LeetCode::Solution40::combinationSum2(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, used);
        return res;
}