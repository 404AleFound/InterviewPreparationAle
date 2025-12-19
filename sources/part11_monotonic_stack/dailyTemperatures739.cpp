#include "part11_monotonic_stack.h"
/*
解题思路：
    当求解序列中右边比某元素大的第一个元素或者比某元素小的第一个元素时就可以使用单调栈：
    - 当求解右边比某元素大的第一个元素时，单调栈应当为头小底大。
    - 当求解右边比某元素小的第一个元素时，单调栈应当为头大底小。

    对于本题，求的是右边第一个大的温度，因此采用的单调栈应当为头小底大。
*/
namespace LeetCode {
std::vector<int> dailyTemperatures739(std::vector<int>& temperatures) {
    std::vector<int> res(temperatures.size(), 0);
    std::stack<int> stk;
    stk.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
        if (temperatures[stk.top()] < temperatures[i]) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                res[stk.top()] = i - stk.top();
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
