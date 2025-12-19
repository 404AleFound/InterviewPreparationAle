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

class Solution {
public:
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
};


#endif // DYNAMIC_PROGRAMMING_H