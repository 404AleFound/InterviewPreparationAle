#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string& s, int left, int right) {
        while(left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backtracking(const string& s, int index) {
        // index 表示分割后第一个字符的索引
        if (index >= s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                // cout << "is Palindrome" << endl;
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            } else {
                // cout << "is Not Palindrome" << endl;
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // aabc
        backtracking(s, 0);
        return res;
    }
};

int main() {
    // Input: "aabc"
    // Output: [["aa", "b", "c"]]
    string s;
    cout << "Input the string: " << endl;
    cin >> s;

    Solution sol;
    vector<vector<string>> ans = sol.partition(s);

    int n = ans.size();
    cout << "The results is: " << endl;
    for(int i = 0; i < n; i++) {
        int numParts = ans[i].size();
        for (int j = 0; j < numParts - 1; j++) {
            cout << ans[i][j] << ", ";
        }
        cout << ans[i][numParts - 1] << endl;
    }
}