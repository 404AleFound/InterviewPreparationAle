#include "part11_monotonic_stack.h"

/*
    题目描述：
    - nums1中数字x的下一个更大元素是指x在nums2中对应位置右侧的第一个比x大的元素。
    - 给你两个没有重复元素的数组nums1和nums2，下标从0开始计数，其中nums1是nums2的子集。
    - 对于每个0<=i<nums1.length，找出满足nums1[i] == nums2[j]的下标j，并且在nums2确定nums2[j]的下一个更大元素。
    - 如果不存在下一个更大元素，那么本次查询的答案是-1 。
    - 返回一个长度为nums1.length的数组ans作为答案，满足ans[i]是如上所述的下一个更大元素 。
*/

/*
    解题思路：
    - 先对nums2中单调元素进行单调栈操作，且设计的单调栈为头小底大的栈。
    - 在提取时，还需要判断nums2中的元素是否在nums1中存在，对于无重复元素的数组，使用unordered_map比较合适。
    - 注意：这里需要返回对应的值，而非索引
    - 注意：无论是否存在于nums1中，都要弹出该元素，即pop操作在判断存在性的if之外。
*/

namespace LeetCode {
std::vector<int> nextGreaterElement496(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> res(nums1.size(), -1);
    std::stack<int> stk;
    std::unordered_map<int, int> umap(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        umap[nums1[i]] = i;
    }
    stk.push(0);
    for (int i = 1; i < nums2.size(); i++) {
        if (nums2[stk.top()] < nums2[i]) {
            while(!stk.empty() && nums2[stk.top()] < nums2[i]) {
                if(umap.count(nums2[stk.top()]) > 0) {
                    res[umap[nums2[stk.top()]]] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        } else {
            stk.push(i);
        }
    }
    return res;
}
}
