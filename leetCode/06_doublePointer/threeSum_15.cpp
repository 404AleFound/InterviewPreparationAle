#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝操作
            if (nums[i] > 0) break;
            // 去重操作
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    res.push_back({vector<int> {nums[i], nums[left], nums[right]}});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right &&  nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    right--;
                }
            }

        }
        return res;
    }
};

int main() {
    int n;
    cout << "Input the length of list to construct a vector: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Input the elements of the vector: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Output the results: " << endl;
    for (size_t i = 0; i < ans.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++) {
            if (j) cout << ", ";
            cout << ans[i][j];
        }
        cout << "]" << endl;
    }
}