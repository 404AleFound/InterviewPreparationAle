#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iomanip>
#include <climits>

namespace LeetCode{

    class Solution77{
    // https://leetcode.cn/problems/combinations/
    // 2026/1/13
    private:
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        void backtracking(int n, int k, int startIndex);
    public:
        std::vector<std::vector<int>> combine(int n, int k);

    };

    class Solution216{
    // https://leetcode.cn/problems/combination-sum-iii/
    // 2026/1/13
    private:
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        int sum = 0;
        void backtracking(int k, int n, int startIndex);
    public:
        std::vector<std::vector<int>> combinationSum3(int k, int n);
    };

    class Solution17{
    // https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
    // 2026/1/13
    private:
        std::unordered_map<char, std::string> dict{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        std::string path;
        std::vector<std::string> res;
        void backtracking(const std::string& digits, int index);
    public:
        std::vector<std::string> letterCombinations(std::string digits);
    };

    class Solution39{
    // https://leetcode.cn/problems/combination-sum/
    // 2026/1/13
    private:
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        int sum = 0;
        void backtracking(const std::vector<int>& candidates, int target, int index);
    public:
        std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
    };

    class Solution40{
    // https://leetcode.cn/problems/combination-sum-ii/submissions/690989430/
    // 2026/1/13
    private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    int sum = 0;
    void backtracking(const std::vector<int>& candidate, int target, int index, std::vector<bool> used);
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
    };

}

#endif