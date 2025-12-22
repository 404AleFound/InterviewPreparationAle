#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
    - 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
    - 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/

/*
    解题思路：
    - dp[i][j]：从(0，0)出发，到达(i，j)有dp[i][j]条路径
    - dp[i][j] = dp[i-1][j] + dp[i][j-1]
    - dp[i][0] = 1，dp[0][j] = 1，dp[0][0] = 1 

*/
int LeetCode::Solution62::uniquePaths(int m, int n){
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    return dp[m-1][n-1];
}