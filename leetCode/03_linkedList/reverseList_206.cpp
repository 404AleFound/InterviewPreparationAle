#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
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

ListNode* getNode(ListNode* head, int index) {
    while(head && index-- > 0) head = head->next;
    return head;
}

ListNode* getTail(ListNode* head) {
    if (!head) return nullptr;
    while(head->next) head = head->next;
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
public:
    ListNode* reverseList(ListNode* head) {
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
};

int main() {
    int n;
    cout << "Input the len of List to construct ListNode: " << endl;
    cin >> n;
    vector<int> list(n);
    cout << "Input the elements of List to construct ListNode: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    ListNode* head = buildList(list);
    cout << "The origin value of linked list is: " << endl;
    print(head);

    Solution sol;
    ListNode* head_new = sol.reverseList(head);
    cout << "The reversed head value of linked list is: " << endl;
    print(head_new);

}
