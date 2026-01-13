#include "part09_backtracking.h"


/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。
 * 注意 1 不对应任何字母。
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 */
void LeetCode::Solution17::backtracking(const std::string& digits, int index) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        std::string strmap = dict[digits[index]];
        for (int i = 0; i < strmap.size(); i++) {
            path.push_back(strmap[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

std::vector<std::string> LeetCode::Solution17::letterCombinations(std::string digits) {
    backtracking(digits, 0);
    return res;
}