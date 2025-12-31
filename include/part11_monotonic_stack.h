#ifndef MONOTONIC_STACK_H
#define MONOTONIC_STACK_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>

namespace LeetCode {

    class Solution739{
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& temperatures);
        // 2025/12/17
        // https://leetcode.cn/problems/daily-temperatures/submissions/685303400/
    };

    class Solution496{
    public:
        std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);
        // 2025/12/17
        // https://leetcode.cn/problems/next-greater-element-i/
    };

    class Solution503{
    public:
        std::vector<int> nextGreaterElements(std::vector<int>& nums);
        // 2025/12/17
        // https://leetcode.cn/problems/next-greater-element-ii/submissions/685312642/
    };

    class Solution42{
    public:
        int trap(std::vector<int>& height);
        // 2025/12/18
        // https://leetcode.cn/problems/trapping-rain-water/
    };

    class Solution84{
    public:
        int largestRectangleArea(std::vector<int>& heights);
        // 2025/12/18
        // https://leetcode.cn/problems/largest-rectangle-in-histogram/
    };

};
#endif // MONOTONIC_STACK_H