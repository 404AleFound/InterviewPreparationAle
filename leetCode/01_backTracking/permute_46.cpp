#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(const vector<int>& nums, int n, vector<bool> used) {
        if (n == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, n + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
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
    vector<vector<int>> ans = sol.permute(nums);

    cout << "Output the results: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size() - 1; j++) {
            cout << ans[i][j] << ", ";
        }
        cout << ans[i][ans[i].size() - 1] << endl;
    }
}