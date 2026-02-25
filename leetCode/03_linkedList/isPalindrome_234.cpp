#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* buildList(const vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

ListNode* getNodeAt(ListNode* head, int idx) {
    while (head && idx-- > 0) head = head->next;
    return head;
}

ListNode* getTail(ListNode* head) {
    if (!head) return nullptr;
    while (head->next) head = head->next;
    return head;
}

void print(ListNode* head) {
    if (!head) return;
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
private:
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }

public: 
    bool isPalindrome(ListNode* head) {
        ListNode* midNode = getMidNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = reverseLinkedList(midNode->next);
        while(leftHead && rightHead) {
            if (leftHead->val != rightHead->val) return false;  
            leftHead = leftHead->next;
            rightHead = rightHead->next;
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Input the length of list ot construct Linked List: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Input the elements of the Linked list: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ListNode* head = buildList(nums);
    Solution sol;
    bool ans = sol.isPalindrome(head);
    if (ans == false) {
        cout << "The linked list IS NOT palindrome." << endl;
    } else {
        cout << "The linked list IS palindrome." << endl;
    }
    return 0;
}