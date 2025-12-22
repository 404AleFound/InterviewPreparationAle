#include "part10_dynamic_programming.h"
/*
    题目描述；
    - 斐波那契数(通常用F(n)表示)形成的序列称为斐波那契数列。
    - 该数列由0和1开始，后面的每一项数字都是前面两项数字的和。
*/

/*
    解题思路：
    - 定义dp数组：dp[i]表示第i个斐波那契数。
    - 定义递推方式：dp[i] = dp[i - 1]  + dp[i - 2]。
    - 初始化dp数组：dp[0] = 0，dp[1] = 1。
    - 确定遍历顺序：从前到后依次遍历即可。
    
*/
int LeetCode::Solution509::fib(int n) {
    if (n < 2) return n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}