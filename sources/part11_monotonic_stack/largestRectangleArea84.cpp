#include "part11_monotonic_stack.h"

/*
    题目描述：
    - 给定n个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为1。
    - 求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

/*
    解题思路：
    - 每次求解包含该柱子的最大矩形。
    - 边界通过左边第一个小于该柱子的索引，和右边第一个小于该柱子的索引确定。
    - 维护一个头大底小的单调栈。
*/

namespace LeetCode {
int largestRectangleArea84(std::vector<int>& heights) {
    std::stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    stk.push(0);
    int res = 0;
    for (int i = 1; i < heights.size(); i++) {
        while(!stk.empty() && heights[stk.top()] > heights[i]) {
            int mid = stk.top();
            int right = i;
            stk.pop();
            int left = stk.top();
            int w = right - left - 1;
            int h = heights[mid];
            res = std::max(res, w * h);
        }  
        stk.push(i);
    }
    return res;
}
}

