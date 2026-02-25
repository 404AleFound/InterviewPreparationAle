#include <iostream>
#include <vector>

using namespace std;

class Solution_1 {
public:
    int findDuplicate(const vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

class Solution_2 {
public:
    int findDuplicate(const vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];   
            if (slow == fast) break;
        }

        int head = 0;
        while (slow != head) {
            slow = nums[slow];
            head = nums[head];
        }
        return slow;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution_1 sol_1;
    Solution_2 sol_2;

    int ans_1 = sol_1.findDuplicate(nums);
    int ans_2 = sol_2.findDuplicate(nums);

    cout << "The answer of method based on BinarySearch: " << ans_1 << endl;
    cout << "The answer of method based on CircularLinkedList: " << ans_2 << endl;
}