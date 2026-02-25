#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(const vector<int>& nums, int index) {
        if (index == nums.size()) {
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back();

        }
    }
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        res.push_back({});
        backtracking(nums, 0);
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
    vector<vector<int>> ans = sol.subsets(nums);

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