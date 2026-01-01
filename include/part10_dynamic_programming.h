#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

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

namespace LeetCode {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

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
    class Solution01bp{
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
    class Solutionfullbp{
    public:
        int fullBackpack(int bagweight, std::vector<int> values, std::vector<int> weights);
        // 2025/12/28
        // https://kamacoder.com/problempage.php?pid=1052
    };

    class Solution518{
    public:
        int change(int amount, std::vector<int>& coins);
        // 2025/12/29
        // https://leetcode.cn/problems/coin-change-ii/description/
    };
    
    class Solution377{
    public:
        int combinationSum4(std::vector<int>& nums, int target);
        // 2025/12/29
        // https://leetcode.cn/problems/combination-sum-iv/
    };

    class Solution322{
    public:
        int coinChange(std::vector<int>& coins, int amount);
        // 2025/12/29
        // https://leetcode.cn/problems/coin-change/
    };

    class Solution279{
    public:
        int numSquares(int n);
        // 2025/12/29
        // https://leetcode.cn/problems/perfect-squares/
    };

    class SolutionStair{
    public:
        int climbStair(int m, int n);
        // 2025/12/31
        // https://kamacoder.com/problempage.php?pid=1067
    };

    class Solution139{
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict);
        // 2025/12/31
        // https://leetcode.cn/problems/word-break/description/
    };


    // ======================================= 多重背包 =======================================
    class SolutionMulbp{
    public:
        int multiBackpack(int bagweight, std::vector<int> values, std::vector<int> weights, std::vector<int> nums);
        // https://leetcode.cn/problems/longest-palindromic-subsequence/
        // 2025/12/30
    };

    // ======================================= 抢劫问题 =======================================
    class Solution198{ 
    public:
        int rob(std::vector<int>& nums);
        // https://leetcode.cn/problems/house-robber/
        // 2025/12/31
    };

    class Solution213{ 
    public:
        int robrange(const std::vector<int>& nums, int start, int end);
        int rob(std::vector<int>& nums);
        // https://leetcode.cn/problems/house-robber-ii/description/
        // 2025/12/31
    };

    class Solution337{
    public:
        int rob(TreeNode* root);
        std::vector<int> robTree(TreeNode* cur); 
    };
    // ======================================= 买卖股票 =======================================
    class Solution121{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/submissions/688493717/
        // 2026/1/1
    };

    class Solution122{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
        // 2026/1/1
    };

    class Solution123{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
        // 2026/1/1
    };

    class Solution188{
    public:
        int maxProfit(int k, std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
        // 2026/1/1
    };

};
#endif // DYNAMIC_PROGRAMMING_H