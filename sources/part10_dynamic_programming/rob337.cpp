#include "part10_dynamic_programming.h"

/*
    题目描述：
    - 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
    - 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
    - 聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
    - 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
    - 给定二叉树的 root 。返回 在不触动警报的情况下，小偷能够盗取的最高金额 。
*/

/*
    解题思路：
    - 
*/

int LeetCode::Solution337::rob(LeetCode::TreeNode* root){
    std::vector<int> res = robTree(root);
    return std::max(res[0], res[1]);
}

std::vector<int> LeetCode::Solution337::robTree(TreeNode* cur){
    if(cur == NULL) return std::vector<int>{0,0};
    // 0: do not rob; 1: do rob
    std::vector<int> left = robTree(cur->left);
    std::vector<int> right = robTree(cur->right);
    int val1 = std::max(left[0], left[1]) + std::max(right[1],right[0]);
    int val2 = cur->val + left[0] + right[0];
    return {val1, val2};
}