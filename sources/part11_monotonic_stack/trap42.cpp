#include "part11_monotonic_stack.h"

/*
    题目描述：
    - 给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

/*
    解题思路：
    - 注意这边计算雨水时要处理宽度
*/
namespace LeetCode{
int trap42(std::vector<int>& height) {
    int res = 0;
    std::stack<int> stk;

    stk.push(0);
    for (int i = 1; i < height.size(); i++) {
        while(!stk.empty() && height[stk.top()] < height[i]) {
            int right = i;
            int mid = stk.top();
            stk.pop();
            if (!stk.empty()) {
                int left = stk.top();
                int h = std::min(height[left], height[right]) - height[mid];
                int w = right - left - 1;
                res += h * w;
            }
        }
        stk.push(i);
    }
    return res;
}
}

