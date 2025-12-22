#include "part11_monotonic_stack.h"

/*
    题目描述：
    - 给定一个循环数组num(nums[nums.length - 1]的下一个元素是nums[0])，返回nums中每个元素的下一个更大元素。
    - 数字x的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，
    - 这意味着你应该循环地搜索它的下一个更大的数。
    - 如果不存在，则输出 -1 。
*/

/*
    解题思路：
    - 复制一份原来的数组即可
*/
namespace LeetCode{
std::vector<int> Solution503::nextGreaterElements(std::vector<int>& nums) {
    std::stack<int> stk;
    std::vector<int> nums_(nums.begin(), nums.end());
    nums_.insert(nums_.end(), nums.begin(), nums.end());
    std::vector<int> res(nums_.size(), -1);

    stk.push(0);
    for (int i = 1; i < nums_.size(); i++) {
        if (nums_[stk.top()] < nums_[i]) {
            while(!stk.empty() && nums_[stk.top()] < nums_[i]) {
                res[stk.top()] = nums_[i];
                stk.pop();
            }
            stk.push(i);
        } else {
            stk.push(i);
        }
    }
    res.resize(res.size() / 2);
    return res;
}
}
