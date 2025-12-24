#include "part10_dynamic_programming.h"

/*
    - 题目描述：
    - 小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。
    - 他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 
    - 小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。
    - 第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。
    - 第二行包含 M 个正整数，代表每种研究材料的所占空间。 
    - 第三行包含 M 个正整数，代表每种研究材料的价值。
    - 输出一个整数，代表小明能够携带的研究材料的最大价值。
*/

/*
    解题思路：二维数组
    - dp[i][j]：当放物品i时，背包容量为j时，能够携带的最大价值
    - dp[i][j] = std::max(dp[i-1][j], values[i] + dp[i-1][j-weights[i]])
    - for j in range(): dp[0][j] = weights[0] < j ? 0 : values[0] 
    - for i in range(): dp[i][0] = 0
    - 迭代顺序：由于每一个dp[i][j]都是从左上角推理出来的，因此先上下迭代，还是先左右迭代，即先迭代背包还是先迭代商品都是可以的。


    解题思路：一维数组以降低内存复杂度
    - dp[i]：当放入材料i时所能携带的研究材料的最大值。
    - dp[i] = std::max(dp[i][j], values[i] + dp[i][j-weights])
    - 初始化：for j in range(): dp[j] = weights[0] < j ? 0 : values[0] 
    - 迭代顺序：由于先迭代背包还是先迭代材料不重要，因此从头到尾依次迭代即可
*/

int LeetCode::Solution01pb::zerOneBackpack(int bagweight, std::vector<int> weights, std::vector<int> values) {
    std::vector<int> dp(bagweight+1, 0);
    for (int j = 0; j <= values.size(); j++) dp[j] = weights[0] < j ? values[0] : 0;

    for (int i = 0; i < values.size(); i++){
        for (int j = bagweight; j >= weights[i]; j--) {
            dp[j] = std::max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }

    return dp[bagweight];
}