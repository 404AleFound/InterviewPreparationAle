#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
    - 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
    - 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/

/*
    解题思路：
    - dp[j]: 当字符串取前j个时，是否可以由wordDict组合而成。
    - if  (当去掉的字符是wordDict中的 && 去掉后的字符串的dp[i] == true) dp[j] = true; else false

*/

bool LeetCode::Solution139::wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordset(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int j = 0; j <= s.size(); j++) {
            for (int i = 0; i < j; i++) {
                std::string word = s.substr(i, j - i);
                if (wordset.find(word) != wordset.end() && dp[i])
                dp[j] = true;
            }
        }   
        return dp[s.size()];
    }