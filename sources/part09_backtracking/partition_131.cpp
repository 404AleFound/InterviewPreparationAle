#include "part09_backtracking.h"


/**
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * 
 * Input: s = "a"
 * Output: [["a"]]
 */


bool LeetCode::Solution131::isPalindrome(const std::string& s, int left, int right) {
        for (int i = left, j = right; i <= j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

void LeetCode::Solution131::backtracking(const std::string& s, int index) {
    if (index >= s.size()) {
        res.push_back(path);
        return;
    }
    for(int i = index; i < s.size(); i++) {
        if (isPalindrome(s, index, i)) {
            std::string temp = s.substr(index, i - index + 1);
            path.push_back(temp);
        } else {
            continue;
        }
        backtracking(s, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<std::string>> LeetCode::Solution131::partition(std::string s) {
    backtracking(s, 0);
    return res;
}