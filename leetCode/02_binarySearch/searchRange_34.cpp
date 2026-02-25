#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 循环结束后，left = right + 1;
        // 此时nums[left - 1] < target，且nums[left] = nums[right + 1] >= target
        // 所以left就是第一个大于等于target的元素下标
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lowerBound(nums, target + 1) - 1;
        return {start, end};
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    Solution sol;
    vector<int> ans = sol.searchRange(nums, target);
    cout << "The answer of search_33 is: " << "{" << ans[0] << ", " << ans[1] << "}" << endl;
}