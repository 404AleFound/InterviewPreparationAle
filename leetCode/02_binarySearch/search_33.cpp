#include <iostream>
#include <vector>

using namespace std;

/**
 * 如果x和target在不同的递增段：
 *  * 当x在第一个递增段，target在第二个递增段，则x在target的左边，去右边找
 *  * 当x在第二个递增段，target在第一个递增段，则x在target的右边，去左边找
 * 如果x和target在相同的递增段：
 *  * 当x小于target，则x在target的左边，去右边找
 *  * 当x大于target，则x在target的右边，去左边找
 * 
 */

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            if (target > nums[n - 1] && x <= nums[n - 1]) { // x在第二段，target在第一段，x在target的右边，去右边找
                right = mid - 1;
            } else if (target <= nums[n - 1] && x > nums[n - 1]) { // x在第一段，target在第二段，x在target的左边，去左边找
                left = mid + 1;
            } else if (x < target) {
                left = mid + 1;
            } else if (x > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
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
    int ans = sol.search(nums, target);
    cout << "The answer of search_33 is: " << ans << endl;
}