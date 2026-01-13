#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
    - 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/

int LeetCode::Solution516::longestPalindromeSubseq(std::string s){
        // 在[i,j]的闭区间内的字符串的最长回文子序列长度为dp[i][j]
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size() - 1];
}



