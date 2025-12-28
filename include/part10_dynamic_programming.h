#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <unordered_map>
#include <stack>
#include <iomanip>

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
        // 2025/12/24
        // https://leetcode.cn/problems/unique-binary-search-trees/description/
    };

    // ======================================= 零一背包 =======================================
    class Solution01pb{
    public:
        int zerOneBackpack(int bagweight, std::vector<int> weights, std::vector<int> values);
        // 2025/12/24
        // https://kamacoder.com/problempage.php?pid=1046
    };

    class Solution416{
    public:
        bool canPartition(std::vector<int>& nums);
        // 2025/12/24
        // https://leetcode.cn/problems/partition-equal-subset-sum/
    };

    class Solution1049{
    public:
        int lastStoneWeightII(std::vector<int>& stones);
        // 2025/12/24
        // https://leetcode.cn/problems/last-stone-weight-ii/description/
    };

    class Solution494{
    public:
        int findTargetSumWays(std::vector<int>& nums, int target);
        // 2025/12/27
        // https://leetcode.cn/problems/target-sum/description/
    };

    class Solution474{
    public:
        int findMaxForm(std::vector<std::string>& strs, int m, int n);
        // 2025/12/28
        // https://leetcode.cn/problems/ones-and-zeroes/

        int count_zero(const std::string& str);
        int count_one(const std::string& str);
    };

    // ======================================= 完全背包 =======================================
    class Solutionfullpb{
    public:
        int fullBackpack(int bagweight, std::vector<int> values, std::vector<int> weights);
        // 2025/12/28
        // https://kamacoder.com/problempage.php?pid=1052
    };

    class Solution647{
    public:
        int countSubstrings647(std::string s);
        // https://leetcode.cn/problems/palindromic-substrings/
    };


    class Solution516{
    public:
        int longestPalindromeSubseq516(std::string s);
        // https://leetcode.cn/problems/longest-palindromic-subsequence/
    };


};
#endif // DYNAMIC_PROGRAMMING_H