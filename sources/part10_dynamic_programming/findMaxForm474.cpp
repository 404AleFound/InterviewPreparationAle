#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
    - 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
    - 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/

/*
    解题思路：
    - 背包容量有两个维度，可以装下m个0，和n个1
    - 每一个字符串就是一个商品，其价值分别为0和1的数量，重量也是
    - dp[i][j][k]：放下索引为i之前的所有字符串，在背包容量为j、k背包中的最大数组个数为dp[i][j][k]
    - 这里可以把三维数组转换为二维滑动数组使用
    - dp[i][j] 表示可以装下i个0，j个1的背包的最大数组个数
    - dp[i][j] = std::max(dp[i][j], dp[i-strs[i].zeros][j-strs[i].ones] + 1) 
    - 遍历方式：类似之前
    - 初始化：
        dp[0][j] = 0
        dp[i][0] = 0
*/
int LeetCode::Solution474::count_zero(const std::string& str) {
    int sum = 0;
    for (char ch : str)
        if (ch == '0') sum += 1;
    return sum;
}

int LeetCode::Solution474::count_one(const std::string& str) {
    int sum = 0;
    for (char ch : str)
        if (ch == '1') sum += 1;
    return sum;
}

int LeetCode::Solution474::findMaxForm(std::vector<std::string>& strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int k = 0; k < strs.size(); k++) {
        int count0 = count_zero(strs[k]);
        int count1 = count_one(strs[k]);
        for (int i = m; i >= count0; i--) {
            for (int j = n; j >= count1; j--) {
                dp[i][j] = std::max(dp[i][j], dp[i - count0][j - count1] + 1);
            }
        }
    }
    return dp[m][n];
}