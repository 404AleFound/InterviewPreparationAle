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

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0;
        int lenB = 0;
        while (currA) {
            lenA++;
            currA = currA->next;    
        }
        while (currB) {
            lenB++;
            currB = currB->next;
        }
        
        currA = headA;
        currB = headB;

        int diffLen = abs(lenA - lenB);

        if (lenA > lenB) {
            for (int i = 0; i < diffLen; i++) currA = currA->next;
        } else {
            for (int i = 0; i < diffLen; i++) currB = currB->next;
        }

        while(currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};

int main () {
    int intersectVal;
    int lenA, lenB;
    int skipA, skipB;
    cout << "Input the intersection node value: " << endl;
    cin >> intersectVal;

    cout << "Input the length of list A and skip length of list A: " << endl;
    cin >> lenA >> skipA;
    vector<int> listA(lenA);
    cout << "Input the elements of list A: " << endl;
    for(int i = 0; i < lenA; i++) cin >> listA[i];

    cout << "Input the length of list B and skip length of list B: " << endl;
    cin >> lenB >> skipB;
    vector<int> listB(lenB);
    cout << "Input the elements of list B: " << endl;
    for(int i = 0; i < lenB; i++) cin >> listB[i];

    if (lenA - skipA != lenB - skipB) {
        std::cout << "Error: lenA - skipA != lenB - skipB" << endl;
        return -1;
    }

    ListNode* headA = buildList(listA);
    ListNode* headB = buildList(listB);
    
    ListNode* inter = getNodeAt(headA, skipA);
    if (!inter && (lenA - skipA) != 0) {
        cout << "Error: invalid skipA" << endl;
        return 1;
    }

    if (skipB == 0) {
        headB = inter;
    } else {
        ListNode* preB = getNodeAt(headB, skipB - 1);
        if (!preB) {
            cout << "Error: invalid skipB" << endl;
            return -1;
        }
        preB->next = inter;
    }

    Solution sol;
    ListNode* ans = sol.getIntersectionNode(headA, headB);

    if (ans) cout << ans->val << endl;
    else cout << "null" << endl;

    return 0;

}

