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
public:
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        while(list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        curr->next = list1 != nullptr ? list1 : list2;
        
        return dummyHead->next;
    }
};

int main() {
    int n1;
    cout << "Input the length of list1 to construct linked list: " << endl;
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Input the elements of list1: " << endl;
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    int n2;
    cout << "Input the length of list2 to construct linked list: " << endl;
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Input the elements of list2" << endl;
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    ListNode* head1 = buildList(nums1);
    ListNode* head2 = buildList(nums2);
    
    cout << "Linked list1 is: " << endl;
    print(head1);
    cout << "Linked list2 is: " << endl;
    print(head2);

    Solution sol;
    ListNode* combinedHead = sol.mergeTwoList(head1, head2);

    cout << "Combined linked list is: " << endl;
    print(combinedHead);
    
}