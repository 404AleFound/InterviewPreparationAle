#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <unordered_map>
#include <stack>

namespace LeetCode {
    class Solution509{
    public:
        int fib(int n);
        // 2025/12/19
        // https://leetcode.cn/problems/fibonacci-number/
    };

    class Solution70{
    public:
        int climbStairs(int n);
        // 2025/12/19
        // https://leetcode.cn/problems/climbing-stairs/
    };

    class Solution746{
    public:
        int minCostClimbingStairs(std::vector<int>& cost);
        // 2025/12/19
        // https://leetcode.cn/problems/climbing-stairs/
    };

    class Solution62{
    public:
        int uniquePaths(int m, int n);
    };

    class Solution63{
    public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
        // 2025/12/19
        // https://leetcode.cn/problems/unique-paths-ii/
    };

    class Solution343{
    public:
        int integerBreak(int n);
        // 2025/12/20
        // https://leetcode.cn/problems/integer-break/
    };

    class Solution96{
    public:
        int numTrees(int n);
    };













void ZerOneBackpack();
// https://kamacoder.com/problempage.php?pid=1046

bool CanPartition416(std::vector<int>& nums);
// LeetCode: https://leetcode.cn/problems/partition-equal-subset-sum/

int LastStoneWeightII1049(std::vector<int>& stones);
// LeetCode: https://leetcode.cn/problems/last-stone-weight-ii/description/

int FindTargetSumWays494(std::vector<int>& nums, int target);
// https://leetcode.cn/problems/target-sum/description/

int FindMaxForm474(std::vector<std::string>& strs, int m, int n);
// https://leetcode.cn/problems/ones-and-zeroes/

int countSubstrings647(std::string s);
// https://leetcode.cn/problems/palindromic-substrings/

int longestPalindromeSubseq516(std::string s);
// https://leetcode.cn/problems/longest-palindromic-subsequence/


};
#endif // DYNAMIC_PROGRAMMING_H