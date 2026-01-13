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

    /**
     * 01
     */
    class Solution509{
    public:
        int fib(int n);
        // 2025/12/19
        // https://leetcode.cn/problems/fibonacci-number/
    };

    /**
     * 02
     */
    class Solution70{
    public:
        int climbStairs(int n);
        // 2025/12/19
        // https://leetcode.cn/problems/climbing-stairs/
    };

    /**
     * 03
     */
    class Solution746{
    public:
        int minCostClimbingStairs(std::vector<int>& cost);
        // 2025/12/19
        // https://leetcode.cn/problems/climbing-stairs/
    };

    /**
     * 03
     */
    class Solution62{
    public:
        int uniquePaths(int m, int n);
    };

    /**
     * 04
     */
    class Solution63{
    public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
        // 2025/12/19
        // https://leetcode.cn/problems/unique-paths-ii/
    };

    /**
     * 05
     */
    class Solution343{
    public:
        int integerBreak(int n);
        // 2025/12/20
        // https://leetcode.cn/problems/integer-break/
    };

    /**
     * 06
     */
    class Solution96{
    public:
        int numTrees(int n);
        // 2025/12/24
        // https://leetcode.cn/problems/unique-binary-search-trees/description/
    };

    // ======================================= 零一背包 =======================================
    /**
     * 07
     */
    class Solution01bp{
    public:
        int zerOneBackpack(int bagweight, std::vector<int> weights, std::vector<int> values);
        // 2025/12/24
        // https://kamacoder.com/problempage.php?pid=1046
    };

    /**
     * 08
     */
    class Solution416{
    public:
        bool canPartition(std::vector<int>& nums);
        // 2025/12/24
        // https://leetcode.cn/problems/partition-equal-subset-sum/
    };

    /**
     * 09
     */
    class Solution1049{
    public:
        int lastStoneWeightII(std::vector<int>& stones);
        // 2025/12/24
        // https://leetcode.cn/problems/last-stone-weight-ii/description/
    };

    /**
     * 10
     */
    class Solution494{
    public:
        int findTargetSumWays(std::vector<int>& nums, int target);
        // 2025/12/27
        // https://leetcode.cn/problems/target-sum/description/
    };

    /**
     * 11
     */
    class Solution474{
    public:
        int findMaxForm(std::vector<std::string>& strs, int m, int n);
        // 2025/12/28
        // https://leetcode.cn/problems/ones-and-zeroes/

        int count_zero(const std::string& str);
        int count_one(const std::string& str);
    };

    // ======================================= 完全背包 =======================================
    /**
     * 12
     */
    class Solutionfullbp{
    public:
        int fullBackpack(int bagweight, std::vector<int> values, std::vector<int> weights);
        // 2025/12/28
        // https://kamacoder.com/problempage.php?pid=1052
    };

    /**
     * 13
     */
    class Solution518{
    public:
        int change(int amount, std::vector<int>& coins);
        // 2025/12/29
        // https://leetcode.cn/problems/coin-change-ii/description/
    };

    /**
     * 14
     */
    class Solution377{
    public:
        int combinationSum4(std::vector<int>& nums, int target);
        // 2025/12/29
        // https://leetcode.cn/problems/combination-sum-iv/
    };

    /**
     * 15
     */
    class Solution322{
    public:
        int coinChange(std::vector<int>& coins, int amount);
        // 2025/12/29
        // https://leetcode.cn/problems/coin-change/
    };

    /**
     * 16
     */
    class Solution279{
    public:
        int numSquares(int n);
        // 2025/12/29
        // https://leetcode.cn/problems/perfect-squares/
    };

    /**
     * 17
     */
    class SolutionStair{
    public:
        int climbStair(int m, int n);
        // 2025/12/31
        // https://kamacoder.com/problempage.php?pid=1067
    };

    /**
     * 18
     */
    class Solution139{
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict);
        // 2025/12/31
        // https://leetcode.cn/problems/word-break/description/
    };


    // ======================================= 多重背包 =======================================
    /**
     * 19
     */
    class SolutionMulbp{
    public:
        int multiBackpack(int bagweight, std::vector<int> values, std::vector<int> weights, std::vector<int> nums);
        // https://leetcode.cn/problems/longest-palindromic-subsequence/
        // 2025/12/30
    };

    // ======================================= 抢劫问题 =======================================

    /**
     * 20
     */
    class Solution198{ 
    public:
        int rob(std::vector<int>& nums);
        // https://leetcode.cn/problems/house-robber/
        // 2025/12/31
    };

    /**
     * 21
     */
    class Solution213{ 
    public:
        int robrange(const std::vector<int>& nums, int start, int end);
        int rob(std::vector<int>& nums);
        // https://leetcode.cn/problems/house-robber-ii/description/
        // 2025/12/31
    };

    /**
     * 22
     */
    class Solution337{
    public:
        int rob(TreeNode* root);
        std::vector<int> robTree(TreeNode* cur); 
    };
    // ======================================= 买卖股票 =======================================

    /**
     * 23
     */
    class Solution121{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/submissions/688493717/
        // 2026/1/1
    };

    /**
     * 24
     */
    class Solution122{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
        // 2026/1/1
    };

    /**
     * 25
     */
    class Solution123{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
        // 2026/1/1
    };

    /**
     * 26
     */
    class Solution188{
    public:
        int maxProfit(int k, std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
        // 2026/1/1
    };

    /**
     * 27
     */
    class Solution309{
    public:
        int maxProfit(std::vector<int>& prices);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
        // 2026/1/2
    };

    /**
     * 28
     */
    class Solution714{
    public:
        int maxProfit(std::vector<int>& prices, int fee);
        // https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
        // 2026/1/2
    };

    // ======================================= 序列问题 =======================================

    /**
     * 29
     */
    class Solution300{
    public:
        int lengthOfLIS(std::vector<int>& nums);
        // https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
        // 2026/1/2
    };

    /**
     * 30
     */
    class Solution674{
    public:
        int findLengthOfLCIS(std::vector<int>& nums);
        // https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
        // 2026/1/2
    };

    /**
     * 31
     */
    class Solution718{
    public:
        int findLength(std::vector<int>& nums1, std::vector<int>& nums2);
        // https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
        // 2026/1/7
    };

    /**
     * 32
     */
    class Solution1143{
        int longestCommonSubsequence(std::string text1, std::string text2);
        // https://leetcode.cn/problems/longest-common-subsequence/
        // 2026/1/7
    };

    /**
     * 33
     */
    class Solution1035{
        int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2);
        // https://leetcode.cn/problems/uncrossed-lines/
        // 2026/1/7
    };

    /**
     * 34
     */
    class Solution53{
        int maxSubArray(std::vector<int>& nums);
        // https://leetcode.cn/problems/maximum-subarray/description/
        // 2026/1/11
    };

    /**
     * 35
     */
    class Solution392{
        bool isSubsequence(std::string s, std::string t);
        // https://leetcode.cn/problems/is-subsequence/description/
        // 2026/1/11
    };

    /**
     * 36
     */
    class Solution115{
        int numDistinct(std::string s, std::string t);
        // https://leetcode.cn/problems/distinct-subsequences/description/
        // 2026/1/11
    };

    /**
     * 37
     */
    class Solution583{
        int minDistance(std::string word1, std::string word2);
        // https://leetcode.cn/problems/delete-operation-for-two-strings/description/
        // 2026/1/11
    };

    /**
     * 38
     */
    class Solution72{
        int minDistance(std::string word1, std::string word2);
        // https://leetcode.cn/problems/edit-distance/description/
        // 2026/1/11
    };

    /**
     * 39
     */
    class Solution647{
        int countSubstring(std::string s);
        // https://leetcode.cn/problems/palindromic-substrings/description/
        // 2026/1/11
    };

    /**
     * 40
     */
    class Solution516{
        int longestPalindromeSubseq(std::string s);
        // https://leetcode.cn/problems/longest-palindromic-subsequence/description/
        // 2026/1/11
    };

};
#endif // DYNAMIC_PROGRAMMING_H