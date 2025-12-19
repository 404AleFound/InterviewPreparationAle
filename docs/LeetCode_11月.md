[toc]





# 2025/11/01

## 01 二分查找

[704. 二分查找 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-search/description/)

> [!NOTE]
>
> 本题的关键是确定区间是左闭右开，对于左闭右开，当`target > nums[mid]`时，`target`位于`mid`的左边，而由于区间必须是左闭右开的，如果写为`left = mid + 1`，此时`left`是没有办法取到等号的，因此应当写为`left = mid + 1`。
>

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (target < nums[mid]) right = mid;
            else if (target > nums[mid]) left = mid + 1;
            else return mid; 
        }
        return -1;
    }
};
```

## 02 移除元素

[27. 移除元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-element/description/)

> [!NOTE]
>
> 快慢指针：快指针用于遍历，慢指针用于记录元素，当快指针找到的元素不是目标元素，则将其记录进慢指针的位置，将慢指针加1用于下一个元素的存储。

```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, len = nums.size();
        for (int fast  = 0; fast < len; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
```

## 03 有序数组的平方

[977. 有序数组的平方 - 力扣（LeetCode）](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n;// 注意right的写法
        while (left < right) {
            int left_squ = nums[left] * nums[left];
            int right_squ = nums[right-1] * nums[right-1];// 注意right的写法
            if (left_squ > right_squ) {
                res[--n] = left_squ;
                left++;
            } else {
                res[--n] = right_squ;
                right--;
            }
        }
        return res;
    }
};
```

## 04 长度最小的子数组

[209. 长度最小的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

```C++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // special cases
        if (nums.size() == 0) return 0 ;
        
        // start!
        int sum = 0;
        int sublength = 0;
        int res = INT32_MAX;
        int left = 0, right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while(sum >= target) {
                sublength = right - left + 1;
                res = sublength < res ? sublength : res;
                sum -= nums[left++];
            }
            right++;
        }
        return res == INT32_MAX ? 0 : res;
    }
};
```

## 05 螺旋数组II

[59. 螺旋矩阵 II - 力扣（LeetCode）](https://leetcode.cn/problems/spiral-matrix-ii/description/)

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector(n ,0));// 初始化注意
        int i = 0, j = 0;
        int startX = 0, startY = 0;
        int count = 1;
        int offset = 0;
        int loop = n / 2;
        while(loop--) {
            i = startX;
            j = startY;
            for(j; j < n - offset - 1; j++) res[i][j] = count++;
            for(i; i < n - offset - 1; i++) res[i][j] = count++;
            for(j; j > startY; j--) res[i][j] = count++;
            for(i; i > startX; i--) res[i][j] = count++;
            offset++; startX++; startY++;
        }
        if (n % 2 != 0) res[n/2][n/2] = n * n;
        return res;

    }
};
```

# 2025/11/02

## 06 移除链表元素

[203. 移除链表元素 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-linked-list-elements/description/)

```C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* curr = head;
        while(curr != nullptr) {
            if (curr->val == val) {
                ListNode* temp = curr;
                pre->next = curr->next;
                curr = pre->next;
                delete temp;
            } else {
                pre = curr;
                curr = curr->next;
            }
        }
        return dummyHead->next;// 注意返回值
    }
};
```

# 2025/11/03

## 07 设计链表

[707. 设计链表 - 力扣（LeetCode）](https://leetcode.cn/problems/design-linked-list/)

```C++
class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr){}
    };

    MyLinkedList() {
        _size = 0;
        _dummyHead = new LinkedNode(0);
    }
    
    int get(int index) {
        if (index > (_size - 1) || index < 0) return -1;

        LinkedNode* curr = _dummyHead->next;;
        while(index--) {
            curr = curr -> next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = _dummyHead;
        // 对于空链表，在尾部插入必须将curr置为隐节点处
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        // special cases
        if (index > _size) return;
        // main body
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = _dummyHead;
        while(index--) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        // special cases
        if (index < 0 || index >= _size) return;
        // main body
        LinkedNode* curr = _dummyHead;
        while(index--) {
            curr = curr->next;
        }
        LinkedNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        temp = nullptr;
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};
```

## 08 反转链表

[206. 反转链表 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-linked-list/)

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;// 反转链表一般不需要设置虚拟头节点
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};
```

## 09 两两交换

[24. 两两交换链表中的节点 - 力扣（LeetCode）](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while(curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* temp = curr->next;
            ListNode* temp_ = curr->next->next->next;
            curr->next = curr->next->next;
            curr->next->next = temp;
            curr->next->next->next = temp_;

            curr = curr->next->next;
        }
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```

## 10 删除倒数第N个节点

[19. 删除链表的倒数第 N 个结点 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

```C++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* left = dummyHead;
        ListNode* right = dummyHead;
        while(n-- && right->next != nullptr) {
            right = right->next;
        }
        while(right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        ListNode* temp = left->next;
        left->next = left->next->next;
        delete temp;
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```

## 11 链表相交

[面试题 02.07. 链表相交 - 力扣（LeetCode）](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/)

```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyHeadA = new ListNode(0);
        ListNode* dummyHeadB = new ListNode(0);
        dummyHeadA->next = headA;
        dummyHeadB->next = headB;

        ListNode* currA = dummyHeadA;
        ListNode* currB = dummyHeadB;
        while (currA != currB) {
            if (currA == nullptr) currA = dummyHeadB;
            else currA = currA->next;
            if (currB == nullptr) currB = dummyHeadA;
            else currB = currB->next;
        }
        return currA;
    }
};
```

# 2025/11/4

## 12 环形链表II:cry:

[142. 环形链表 II - 力扣（LeetCode）](https://leetcode.cn/problems/linked-list-cycle-ii/)

```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* index1 = head;
                ListNode* index2 = slow;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
```

## 13 有效的字母异位符

[242. 有效的字母异位词 - 力扣（LeetCode）](https://leetcode.cn/problems/valid-anagram/)

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26];
        for (char ch : s) record[ch - 'a']++;
        for (char ch : t) record[ch - 'a']--;
        for (int r : record) if (r != 0) return false;
        return true;
    }
};
```

## 14 两个数组交集

[349. 两个数组的交集 - 力扣（LeetCode）](https://leetcode.cn/problems/intersection-of-two-arrays/)

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) res.insert(num);
        }
        return vector<int> (res.begin(), res.end());

    }
};
```

## 15 判断欢乐数

[202. 快乐数 - 力扣（LeetCode）](https://leetcode.cn/problems/happy-number/)

```C++
class Solution {
public:
    int get_sum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sums;
        while(n != 1) {
            n = get_sum(n);
            if (sums.find(n) != sums.end()) return false;
            sums.insert(n);
        }
        return true;
    }
};
```

## 16 两数之和

[1. 两数之和 - 力扣（LeetCode）](https://leetcode.cn/problems/two-sum/)

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            }
            map.insert({nums[i], i});
        }
        return {};
    }
};
```

# 2025/11/05

## 17 四数相加II

[454. 四数相加 II - 力扣（LeetCode）](https://leetcode.cn/problems/4sum-ii/)

```C++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                umap[-nums1[i] - nums2[j]]++;
            }
        }

        int count = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (umap.find(nums3[i] + nums4[j]) != umap.end())
                    count += umap[nums3[i] + nums4[j]];
            }
        }
        return count;
    }
};
```

## 18 赎金信

[383. 赎金信 - 力扣（LeetCode）](https://leetcode.cn/problems/ransom-note/submissions/675970467/)

```C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (char ch : magazine) record[ch - 'a']++;
        for (char ch : ransomNote)
            if (--record[ch - 'a'] < 0) return false;
        return true;
    }
};
```

## 19 三数之和:cry:

[15. 三数之和 - 力扣（LeetCode）](https://leetcode.cn/problems/3sum/description/)

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < len; i++) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = len - 1;
            while(left < right) {
                if (nums[left] + nums[right] > -nums[i]) right--;
                else if (nums[left] + nums[right] < -nums[i]) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 初始化方式学习
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // 注意添加控制条件
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
```

## 20 四数之和:cry:

[18. 四数之和 - 力扣（LeetCode）](https://leetcode.cn/problems/4sum/)

```C++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
            if(nums[i] >= 0 && nums[i] > target) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len; j++) {
                if(nums[j] >= 0 && nums[j] + nums[i] > target) break;
                // 二级剪枝操作注意细节
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = len - 1;
                while(left < right) {
                    if ((long) nums[left] + nums[right] + nums[i] + nums[j] > target) right--;
                    else if ((long) nums[left] + nums[right] + nums[i] + nums[j] < target) left++;
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
```

# 2025/11/06

## 21 反转字符串

[344. 反转字符串 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-string/)

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            int temp = s[n - 1 - i];
            s[n - 1 - i] = s[i];
            s[i] = temp;
        }
        return;
    }
};
```

## 22 反转字符串II

[541. 反转字符串 II - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-string-ii/)

```C++
class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
            reverse(s, i, min(i + k - 1, n - 1));
        return s;
    }
};
```

## 23 替换数字

[54. 替换数字（第八期模拟笔试）](https://kamacoder.com/problempage.php?pid=1064)

```C++
#include<iostream>
#include<string>
int main() {
  std::string s;
  while(std::cin >> s) {
    int len_old = s.size();
    int count = 0;
    for (int i = 0; i < len_old; i++) {
      if (s[i] >= '0' && s[i] <= '9') count++;
    }
    s.resize(len_old + 5 * count);
    int len_new = s.size();
    int last = len_new - 1;
    for (int j = len_old - 1; j >= 0; j--) {
      if (s[j] >= '0' && s[j] <= '9') {
        s[last--] = 'r';
        s[last--] = 'e';
        s[last--] = 'b';
        s[last--] = 'm';
        s[last--] = 'u';
        s[last--] = 'n';
      } else s[last--] = s[j];
    }
    std::cout << s << std::endl;
  }
}
```

## 24 反转字符串中的单词:cry:

[151. 反转字符串中的单词 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-words-in-a-string/)

```C++
class Solution {
public:
    void removeExtraSpace(string& s) {
        int n = s.size();
        int slow = 0;
        for(int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while(i < n && s[i] != ' ') 
                    s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }

    void reverseString(string& s, int start, int end) {
        if (!(start <= end)) return;
        for (int i = start, j =end; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return;
    }

    string reverseWords(string s) {
        removeExtraSpace(s);
        int n = s.size();
        reverseString(s, 0, n-1);
        int start = 0;
        for(int i = 0; i <= n; i++) {
            if (s[i] == ' ' || i == n) {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
```

# 2025/11/07

## 25 右旋字符串

[55. 右旋字符串（第八期模拟笔试）](https://kamacoder.com/problempage.php?pid=1065)

```C++
#include<iostream>
using namespace std;
void reverse(string& s, int start, int end) {
    if (!(start < end)) return;
    for(int i = start, j = end; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    int n;
    string s;

    if (cin >> n >> s) {
        int len = s.size();
        reverse(s, 0, len-1);
        reverse(s, 0, n-1);
        reverse(s, n, len-1);
        cout << s;
    }
}
```

## 26 实现`strStr()`:cry:

[28. 找出字符串中第一个匹配项的下标 - 力扣（LeetCode）](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

```c++
class Solution {
public:
    vector<int> nextTable(const string& s) {
        int i = 0;
        int len = s.size();
        vector<int> next(len, 0);
        for (int j = 1; j < len; j++) {
            while(i > 0 && s[j] != s[i]) {
                i = next[i - 1];
            }
            if (s[i] == s[j]) i++;
            next[j] = i;
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        if (haystack.size()==0) return -1;

        vector<int> next = nextTable(needle);
        int i = 0;
        int len_hay = haystack.size();
        for (int j = 0; j < len_hay; j++) {
            while(i > 0 && needle[i] != haystack[j]) {
                i = next[i - 1];
            }
            if (needle[i] == haystack[j]) i++;
            if (i == needle.size()) return j - needle.size() + 1;
        }
        return -1;
    }
};
```

## 27 重复子字符串:cry:

[459. 重复的子字符串 - 力扣（LeetCode）](https://leetcode.cn/problems/repeated-substring-pattern/description/)

```C++
class Solution {
public:
    vector<int> nextTable(const string& s) {
        int len = s.size();
        int j = 0;
        vector<int> next(len, 0);
        for (int i = 1; i < len; i++) {
            // next从1开始
            while(j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
        return next;
    }
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        vector<int> next = nextTable(s);
        if (len == 0) return false;
        if (next[len - 1] != 0 && (len % (len - next[len - 1]) == 0)) return true;
        return false;
    }
};
```

## 28 用栈实现队列

[232. 用栈实现队列 - 力扣（LeetCode）](https://leetcode.cn/problems/implement-queue-using-stacks/)

```c++
class MyQueue {
public:
    stack<int> stk_in;
    stack<int> stk_out;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk_in.push(x);
    }
    
    int pop() {
        if (stk_out.size() == 0) {
            while(!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        } 
        auto res = stk_out.top();
        stk_out.pop();
        return res;
    }
    
    int peek() {
        auto res = this->pop();
        stk_out.push(res);
        return res;
    }
    
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }
};
```

## 29 用队列实现栈

[225. 用队列实现栈 - 力扣（LeetCode）](https://leetcode.cn/problems/implement-stack-using-queues/)

```c++
class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int n = que.size();
        n--;// 很关键
        while(n--) {
            int val = que.front();
            que.push(val);
            que.pop();
        }
        int val = que.front();
        que.pop();
        return val;
    }
    
    int top() {
        int val = this->pop();
        this->push(val);
        return val;
    }
    
    bool empty() {
        return que.empty();
    }
};
```

## 30 有效的括号

[20. 有效的括号 - 力扣（LeetCode）](https://leetcode.cn/problems/valid-parentheses/submissions/676587919/)

```C++
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if (len % 2 != 0) return false;

        unordered_map<char,char> map = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        stack<int> stk;
        for (char ch : s) {
            if (map.count(ch)) {
                if (stk.empty() || stk.top() != map[ch]) return false;
                stk.pop();
            } else stk.push(ch);
        }
        return stk.empty();
    }
};
```

# 2025/11/08

## 31 删除字符串中的所有相邻重复项

[1047. 删除字符串中的所有相邻重复项 - 力扣（LeetCode）](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

```C++
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char ch : s) {
            if (res.empty() || res.back() != ch) res.push_back(ch);
            else res.pop_back();
        }
        return res;
    }
};
```

## 32 逆波兰表达式求值

[150. 逆波兰表达式求值 - 力扣（LeetCode）](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for (string ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                long num1 = stk.top();
                stk.pop();
                long num2 = stk.top();
                stk.pop();
                long res;
                if (ch == "+") res = num2 + num1;
                if (ch == "-") res = num2 - num1;
                if (ch == "*") res = num2 * num1;
                if (ch == "/") res = num2 / num1;
                stk.push(res);
            } else {
                stk.push(stoll(ch));
            }
        }
        long res = stk.top();
        stk.pop();
        return res;
    }
};
```

## 33 区间和

[58. 区间和（第九期模拟笔试）](https://kamacoder.com/problempage.php?pid=1070)

```C++
#include<iostream>
#include<vector>

int main() {
    int n, a, b;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int> sumPre(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> vec[i];
        sum += vec[i];
        sumPre[i] = sum;
    }
    while(std::cin >> a >> b) {
        int res = sumPre[b] - sumPre[a-1];
        std::cout << res << std::endl;
    }
}
```

## 34 开发商购买土地

[44. 开发商购买土地（第五期模拟笔试）](https://kamacoder.com/problempage.php?pid=1044)

```C++
#include<iostream>
#include<vector>
#include <climits>

int main() {
    int m, n;
    std::cin >> n >> m;
    std::vector<std::vector<int>> table(n, std::vector<int>(m, 0));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> table[i][j];
            sum+= table[i][j];
        }
    }

    int count = 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += table[i][j];
            if ( j == m - 1) 
                res = std::min(res, abs(sum - count - count));
        }
    }

    count = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            count += table[i][j];
            if ( i == n - 1) 
                res = std::min(res, abs(sum - count - count));
        }
    }
    std::cout << res << std::endl;
}
```

## 35 滑动窗口最大值

[239. 滑动窗口最大值 - 力扣（LeetCode）](https://leetcode.cn/problems/sliding-window-maximum/)

```C++
class Solution {
private:
    struct myQueue{
        deque<int> que;

        void pop(int val) {
            if (!que.empty() && que.front() == val) {
                que.pop_front();
            }
        }
        void push(int val) {
            while (!que.empty() && que.back() < val) {
                que.pop_back();
            }
            que.push_back(val);
        }

        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        myQueue que;
        for (int i = 0; i < k; i++)
            que.push(nums[i]);
        res.push_back(que.front());
        for(int left = 1, right = k; right < len; right++,left++) {
            que.pop(nums[left-1]);
            que.push(nums[right]);
            res.push_back(que.front());
        }
        return res;
    }
};
```

# 2025/11/09

## 36 前K个高频元素

[347. 前 K 个高频元素 - 力扣（LeetCode）](https://leetcode.cn/problems/top-k-frequent-elements/)

```C++
class Solution {
public:
    struct myComparison{
        bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, myComparison> pri_que;
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            pri_que.push(*iter);
            if (pri_que.size() > k) pri_que.pop();
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
```

# 2025/11/10

## 37 二叉树的递归遍历

[94. 二叉树的中序遍历 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-inorder-traversal/submissions/677055315/)、[145. 二叉树的后序遍历 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-postorder-traversal/submissions/677054319/)、[144. 二叉树的前序遍历 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-preorder-traversal/submissions/677053872/)

```C++
// 中序遍历
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
```

```C++
// 后序遍历
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
```

```C++
// 前序遍历递归写法
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
```

## 38 二叉树的迭代遍历

```C++
// 前序遍历循环写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res; 
        stack<TreeNode*> stk;
        if (root == nullptr) return res;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return res;
    }
};
```

```C++
// 后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr) return res;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

```C++
// 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(curr != nullptr || !stk.empty()) {
            if (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                curr = stk.top();
                stk.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};
```

# 2025/11/11

## 39 二叉树的层次遍历

[102. 二叉树的层序遍历 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

```C++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        TreeNode* curr = root;
        if (curr != nullptr) que.push(curr);
        
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
```

## 40 二叉树的层次遍历II

[107. 二叉树的层序遍历 II - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

```C++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* curr = root;
        if(curr != nullptr) que.push(curr);
        vector<vector<int>> res;
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 41 二叉树的右视图

[199. 二叉树的右视图 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-right-side-view/)

```C++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        TreeNode* curr = root;
        if (curr != nullptr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == size - 1) res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};
```

## 42 二叉树的层平均值

[637. 二叉树的层平均值 - 力扣（LeetCode）](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

```C++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        TreeNode* curr = root;
        if (curr != nullptr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};
```

## 43 多叉树的层次遍历

[429. N 叉树的层序遍历 - 力扣（LeetCode）](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/submissions/677410932/)

```C++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        Node* curr = root;
        if (curr != nullptr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j]) que.push(node->children[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
```

## 44 每一个树行寻找最大值

[515. 在每个树行中找最大值 - 力扣（LeetCode）](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)

```C++
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        TreeNode* curr = root;
        if (curr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            int max = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->val > max) max = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
```

## 45 填充每个节点的下一个右侧节点指针

[116. 填充每个节点的下一个右侧节点指针 - 力扣（LeetCode）](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)

```C++
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        Node* curr = root;
        if(curr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            Node* preNode;
            Node* Node;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    preNode = que.front();
                    que.pop();
                    Node = preNode;
                } else {
                    Node = que.front();
                    que.pop();
                    preNode->next = Node;
                    preNode = Node;
                }
                if (Node->left) que.push(Node->left);
                if (Node->right) que.push(Node->right);
            }
            preNode->next = nullptr;
        }
        return root;
    }
};
```

## 46 填充每个节点的下一个右侧节点指针II

[117. 填充每个节点的下一个右侧节点指针 II - 力扣（LeetCode）](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)

```C++
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        Node* curr = root;
        if(curr) que.push(curr);
        while(!que.empty()) {
            int size = que.size();
            Node* preNode;
            Node* Node;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    preNode = que.front();
                    que.pop();
                    Node = preNode;
                } else {
                    Node = que.front();
                    que.pop();
                    preNode->next = Node;
                    preNode = Node;
                }
                if (Node->left) que.push(Node->left);
                if (Node->right) que.push(Node->right);
            }
            Node->next = nullptr;
        }
        return root;
    }
};
```

## 47 二叉树的最大深度

[104. 二叉树的最大深度 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/677451082/)

> [!NOTE]
>
> 本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。
>
> - 二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
> - 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）
> - 深度自上向下增长（先处理，后遍历）；高度自下向上增长（先遍历，后处理）

```C++
// 递归写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
```

```C++
// 循环写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* curr = root;
        if (curr) que.push(curr);
        int max_depth = 0;
        while(!que.empty()) {
            int size = que.size();
            max_depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return max_depth;
    }
};
```

## 48 二叉树的最小深度

[104. 二叉树的最大深度 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/677451082/)

> [!NOTE]
>
> 本题依然是**前序遍历**和**后序遍历**都可以，前序求的是深度，后序求的是高度。
>
> - 二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
> - 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）
> - 深度自上向下增长（先处理，后遍历）；高度自下向上增长（先遍历，后处理）

```C++
// 使用递归
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```

```C++
// 使用循环
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int min_depth = 0;
        while(!que.empty()){
            int size = que.size();
            min_depth++;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) return min_depth;
            }
        }
        return min_depth;
    }
};
```

# 2025/11/12

## 49 翻转二叉树

[226. 翻转二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/invert-binary-tree/submissions/677527367/)

```C++
// 基于前序遍历递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

```C++
// 基于后序遍历递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};
```

## 50 对称二叉树

[101. 对称二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/symmetric-tree/)

```C++
class Solution {
public:
    bool isSymmetric_(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool outside = isSymmetric_(left->left, right->right);
        bool inside = isSymmetric_(left->right, right->left);
        
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric_(root->left, root->right);
    }
};
```

## 51 完全二叉树的节点个数

[222. 完全二叉树的节点个数 - 力扣（LeetCode）](https://leetcode.cn/problems/count-complete-tree-nodes/description/)

```C++
// 直接遍历，并计数
class Solution {
public:
    int getNodeSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftSum = getNodeSum(root->left);
        int rightSum = getNodeSum(root->right);
        int sum = leftSum + rightSum + 1;
        return sum;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return getNodeSum(root);
    }
};
```

```C++
// 利用完全二叉树的性质
class Solution {
public:
    int getNodeSum(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int depthLeft = 0, depthRight = 0;
        while(left) {left = left->left; depthLeft++;}
        while(right) {right = right->right; depthRight++;}
        if (depthLeft == depthRight) return (2 << depthLeft) - 1;

        int sumLeft = getNodeSum(root->left);
        int sumRight = getNodeSum(root->right);
        return sumLeft + sumRight + 1;

    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return getNodeSum(root);
    }
};
```

## 52 平衡二叉树的判断

[110. 平衡二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/balanced-binary-tree/submissions/677753640/)

```C++
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1;

        int res;
        if (abs(leftHeight - rightHeight) > 1) res = -1;
        else res = 1 + max(leftHeight, rightHeight);
        return res;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
```

# 2025/11/14

## 53 二叉树的所有路径

[257. 二叉树的所有路径 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-paths/description/)

```cpp
class Solution {
private:
    void traversal(TreeNode* curr, vector<int>& path, vector<string>& res) {
        path.push_back(curr->val);
        // end condition
        if (curr->left == nullptr && curr->right == nullptr) {
            string sPath;
            for (int i = 0;i < path.size()-1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            res.push_back(sPath);
            return;
        }
        if (curr->left) {
            traversal(curr->left, path, res);
            path.pop_back();
        }
        if (curr->right) {
            traversal(curr->right, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        if (root == nullptr) return res;
        traversal(root, path, res);
        return res;
    }
};
```

## 54 左叶子之和

[404. 左叶子之和 - 力扣（LeetCode）](https://leetcode.cn/problems/sum-of-left-leaves/description/)

```C++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;

        int leftValue = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right)
            leftValue += root->left->val;

        int rightValue = sumOfLeftLeaves(root->right);
        return leftValue + rightValue;
    }
};
```

## 55 找树左下角值

[513. 找树左下角的值 - 力扣（LeetCode）](https://leetcode.cn/problems/find-bottom-left-tree-value/description/)

```C++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int res = 0;
        while (!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) res = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        } 
        return res;
    }
};
```

## 56 路径总和

[112. 路径总和 - 力扣（LeetCode）](https://leetcode.cn/problems/path-sum/description/)

```C++
class Solution {
private: 
    bool traversal(TreeNode* curr, int count) {
        if (!curr->left && !curr->right && count == 0) return true;
        if (!curr->left && !curr->right && count != 0) return false;

        if (curr->left) {
            count -= curr->left->val;
            if (traversal(curr->left, count)) return true;
            count += curr->left->val;
        }

        if (curr->right) {
            count -= curr->right->val;
            if (traversal(curr->right, count)) return true;
            count += curr->val;
        }
        return false;
}
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return traversal(root, targetSum - root->val);
    }
};
```

# 2025/11/15

## 57 从中序与后序遍历序列构造二叉树

[106. 从中序与后序遍历序列构造二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)

```C++
class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;

        int rootValue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootValue);

        if (postorder.size() == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
            if (inorder[delimiterIndex] == rootValue) break;

        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};
```

## 58 最大二叉树

[654. 最大二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-binary-tree/description/)

```C++
class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        int maxValueIndex = left;
        for(int i = left; i < right; i++)
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;

        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex + 1, right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return traversal(nums, 0, nums.size());    
    }
};
```

# 2025/11/17

## 59 合并二叉树

[617. 合并二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/merge-two-binary-trees/description/)

```C++
class Solution {
public:
    TreeNode* traversal(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        root1->left = traversal(root1->left, root2->left);
        root1->right = traversal(root1->right, root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traversal(root1, root2);
    }
};
```

## 60 二叉搜索树中的搜索

[700. 二叉搜索树中的搜索 - 力扣（LeetCode）](https://leetcode.cn/problems/search-in-a-binary-search-tree/description/)

```C++
class Solution {

public:
    TreeNode* traversal(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;

        TreeNode* res = nullptr;
        if (val > root->val) res = traversal(root->right, val);
        if (val < root->val) res = traversal(root->left, val);

        return res;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};

```

## 61 验证二叉搜索树

[98. 验证二叉搜索树 - 力扣（LeetCode）](https://leetcode.cn/problems/validate-binary-search-tree/description/)

```C++
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        traversal(root->left, vec);
        vec.push_back(root->val);
        traversal(root->right, vec);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        for (int i = 1; i < vec.size(); i++)
            if (vec[i] <= vec[i-1]) return false;
       return true; 
    }
};
```

## 62 二叉搜索树的最小绝对差

[530. 二叉搜索树的最小绝对差 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/)

```C++
class Solution {
public:
    TreeNode* pre = nullptr;
    int res = INT_MAX;

    void traversal(TreeNode* curr) {
        if (curr == nullptr) return;
        traversal(curr->left);
        if (pre) res = min(res, curr->val - pre->val);
        pre = curr;
        traversal(curr->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
```

## 63 二叉搜索树中的众数

[501. 二叉搜索树中的众数 - 力扣（LeetCode）](https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/)

```C++
class Solution {
public:
    TreeNode* pre = nullptr;
    vector<int> res;
    int count, maxCount = 0;

    void traversal(TreeNode* curr) {
        if (!curr) return;
        traversal(curr->left);

        if (pre == nullptr) 
            count = 1;
        else if (curr->val == pre->val)
            count++; 
        else 
            count = 1;

        pre = curr;

        if (count == maxCount)
            res.push_back(curr->val);
        else if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(curr->val);
        }
        traversal(curr->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
};
```

# 2025/11/18

## 64 二叉树的最近公共祖先

[236. 二叉树的最近公共祖先 - 力扣（LeetCode）](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        
        if (leftNode && rightNode) return root;
        if (leftNode && !rightNode) return leftNode;
        else if(!leftNode && rightNode) return rightNode;
        else return nullptr;
    }
};
```



## 65 二叉搜索树的最近公共祖先

[235. 二叉搜索树的最近公共祖先 - 力扣（LeetCode）](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (!root) return nullptr;

        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if (left) return left;
        }

        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (right) return right;
        }

        return root;
    }
};
```

## 66 二叉搜索树中的插入操作

[701. 二叉搜索树中的插入操作 - 力扣（LeetCode）](https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/)

```C++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```

## 67 删除二叉搜索树中的节点

[450. 删除二叉搜索树中的节点 - 力扣（LeetCode）](https://leetcode.cn/problems/delete-node-in-a-bst/description/)

```C++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            if (!(root->left) && !(root->right)) {
                delete root;
                return nullptr;
            }
            else if (!(root->left)) {
                TreeNode* resNode = root->right;
                delete root;
                return resNode;
            }
            else if (!(root->right)) {
                TreeNode* resNode = root->left;
                delete root;
                return resNode;
            }
            else {
                TreeNode* curr = root->right;
                while(curr->left) curr = curr->left;
                curr->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
```

## 68 修建二叉搜索树

[669. 修剪二叉搜索树 - 力扣（LeetCode）](https://leetcode.cn/problems/trim-a-binary-search-tree/description/)

```C++
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) {
            TreeNode* newRight = trimBST(root->right, low, high);
            return newRight;
        }
        if (root->val > high) {
            TreeNode* newLeft = trimBST(root->left, low, high);
            return newLeft;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```

## 69 将有序数组转换为二叉搜索树

[108. 将有序数组转换为二叉搜索树 - 力扣（LeetCode）](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/)

```C++
class Solution {
public:
    TreeNode* createTree(vector<int> nums, int left, int right) {
        if (right < left) return nullptr;
        int mid =  (left + right)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums, left, mid-1);
        root->right = createTree(nums, mid+1, right);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size()-1);
    }
};
```

## 70 把二叉搜索树转换为累加树

[538. 把二叉搜索树转换为累加树 - 力扣（LeetCode）](https://leetcode.cn/problems/convert-bst-to-greater-tree/description/)

```C++
class Solution {
public:
    int preSum = 0;
    void traversal(TreeNode* curr) {
        if (!curr) return;
        traversal(curr->right);
        curr->val += preSum;
        preSum = curr->val;
        traversal(curr->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        traversal(root);
        return root;
    }
};
```

# 2025/11/20

## 71 组合

[77. 组合 - 力扣（LeetCode）](https://leetcode.cn/problems/combinations/submissions/679441574/)

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = startindex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backtracking(n, k, 1);
        return res;
    }
};
```

剪枝操作后

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = startindex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backtracking(n, k, 1);
        return res;
    }
};
```

## 72 组合总和II

[216. 组合总和 III - 力扣（LeetCode）](https://leetcode.cn/problems/combination-sum-iii/)

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> vec;
    int sum;
    void backtracking(int k, int n, int startIndex) {
        if (vec.size() == k) {
            if (sum == n) res.push_back(vec);
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            vec.push_back(i);
            sum += i;
            backtracking(k, n, i + 1);
            sum -= i;
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vec.clear();
        backtracking(k, n, 1);
        return res;
    }
};
```

## 73 电话号码的组合

[17. 电话号码的字母组合 - 力扣（LeetCode）](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

```C++
class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

public:
    vector<string> res;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); i++) {
            s.push_back(letter[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if (digits.size() == 0) return res;
        backtracking(digits, 0);
        return res;
    }
};
```

## 74 组合总和

[39. 组合总和 - 力扣（LeetCode）](https://leetcode.cn/problems/combination-sum/)

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> vec;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (sum == target) {
            res.push_back(vec);
            return;
        }
        if (sum > target) return;

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            vec.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i];
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        vec.clear();
        backtracking(candidates, target, 0);
        return res;
    }
};
```

# 2025/11/21

## 75 子集

[78. 子集 - 力扣（LeetCode）](https://leetcode.cn/problems/subsets/)

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(const vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backTracking(nums, 0);
        return res;
    }
};
```

## 76 复原IP地址

[93. 复原 IP 地址 - 力扣（LeetCode）](https://leetcode.cn/problems/restore-ip-addresses/submissions/679795960/)

```C++
class Solution {
public:
    vector<string> res;
    bool isIP(const string& str, int startIndex, int endIndex) {
        if (startIndex > endIndex) return false;
        if (str[startIndex] == '0' && startIndex != endIndex) return false;
        int num = 0;
        for (int i = startIndex; i <= endIndex; i++) {
            if (str[i] > '9' || str[i] < '0') return false;
            num = num * 10 + (str[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }

    void backTracking(string& str, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isIP(str, startIndex, str.size()-1))
                res.push_back(str);
            return;
        }

        for (int i = startIndex; i < str.size(); i++) {
            if (isIP(str, startIndex, i)) {
                str.insert(str.begin() + i + 1, '.');
                pointNum++;
                backTracking(str, i + 2, pointNum);
                pointNum--;
                str.erase(str.begin() + i + 1);
            } else continue;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backTracking(s, 0, 0);
        return res;
    }
};
```



## 77 组合总和II

[40. 组合总和 II - 力扣（LeetCode）](https://leetcode.cn/problems/combination-sum-ii/submissions/679789625/)

```C++
class Solution {
public:
    int sum;
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        if (sum > target) return;


        for(int i = startIndex; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        res.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }
};
```



## 78 分割回文串

[131. 分割回文串 - 力扣（LeetCode）](https://leetcode.cn/problems/palindrome-partitioning/submissions/679792293/)

```C++
class Solution {
public:
    vector<vector<string>> res;
    vector<string> vec;
    bool isPalindrome(const string& str, int startIndex, int endIndex) {
        for (int i = startIndex, j = endIndex; i < j; i++, j--)
            if (str[i] != str[j]) return false;
        return true;
    }

    void backtracking(const string& str, int startIndex) {
        if (startIndex >= str.size()) {
            res.push_back(vec);
            return;
        }

        for (int i = startIndex; i < str.size(); i++) {
            if (isPalindrome(str, startIndex, i)) {
                string s = str.substr(startIndex, i - startIndex + 1);
                vec.push_back(s);
            } else {
                continue;
            }
            backtracking(str, i + 1);
            vec.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        res.clear();
        vec.clear();
        backtracking(s, 0);
        return res;
    }
};
```

## 79 子集II

[90. 子集 II - 力扣（LeetCode）](https://leetcode.cn/problems/subsets-ii/submissions/679799356/)

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(const vector<int>& nums, int startIndex, vector<bool> used) {
        res.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, 0, used);
        return res;
    }
};
```

## 80 递增子序列

[491. 非递减子序列 - 力扣（LeetCode）](https://leetcode.cn/problems/non-decreasing-subsequences/)

```C++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) 
                || uset.find(nums[i]) != uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backTracking(nums,0);
        return res;
    }
};
```

# 2025/11/22

## 81 全排列

[46. 全排列 - 力扣（LeetCode）](https://leetcode.cn/problems/permutations/)

```C++
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backTracking(vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return res;
    }
};
```



## 82 全排列II

[47. 全排列 II - 力扣（LeetCode）](https://leetcode.cn/problems/permutations-ii/)

```C++
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backTracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;            
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backTracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return res;
    }
};
```

# 2025/11/25

## 83 分发饼干

[455. 分发饼干 - 力扣（LeetCode）](https://leetcode.cn/problems/assign-cookies/)

```C++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int s_end = s.size() - 1;
        int res = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (s_end >= 0 && g[i] <= s[s_end]) {
                s_end--;
                res++;
            }
        }
        return res;
    }
};
```

让胃口大的孩子先被满足，使得有更大的饼干可以分配给后面的孩子。

## 84 摆动序列

[376. 摆动序列 - 力扣（LeetCode）](https://leetcode.cn/problems/wiggle-subsequence/description/)

```C++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        int curDiff = 0;
        int preDiff = 0;
        int res = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i+1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) ||(curDiff < 0 && preDiff >= 0)) {
                preDiff = curDiff;
                res++;
            }
        }
        return res;
    }
};
```

## 85 最大子序和

[53. 最大子数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-subarray/description/)

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > res) res = sum;
            if (sum <= 0) sum = 0;
        }
        return res;
    }
};
```

设置累加器，当累加器为负数马上清零。

## 86 买卖股票的最佳实际II

[122. 买卖股票的最佳时机 II - 力扣（LeetCode）](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            res += max(prices[i + 1] - prices[i], 0);
        }
        return res;
    }
};
```

## 87 跳跃游戏

[55. 跳跃游戏 - 力扣（LeetCode）](https://leetcode.cn/problems/jump-game/)

```C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, nums[i] + i);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
```

注意，这里for循环内部为`<= cover`

## 88 跳跃游戏II

[45. 跳跃游戏 II - 力扣（LeetCode）](https://leetcode.cn/problems/jump-game-ii/)

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int currDistance = 0;
        int nextDistance = 0;
        int n_step = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nextDistance, nums[i] + i);
            if (i == currDistance) {
                currDistance = nextDistance;
                n_step++;
                if (nextDistance >= nums.size() - 1) return n_step;
            }
        }
        return n_step;
    }
};
```

## 89 K此取反后最大化的数组和

[1005. K 次取反后最大化的数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/submissions/680652883/)

```C++
class Solution {
public:
    static bool cmp(int a, int b) { // 这里的static很重要
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        int sum = 0;
        for (int num: nums) sum += num;
        return sum; 
    }
};
```

# 2025/11/26

## 90 加油站

[134. 加油站 - 力扣（LeetCode）](https://leetcode.cn/problems/gas-station/submissions/680934354/)

```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};
```

## 91 分发糖果

[135. 分发糖果 - 力扣（LeetCode）](https://leetcode.cn/problems/candy/submissions/680939159/)

```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        
        for(int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) candyVec[i] = candyVec[i-1] + 1;
        }

        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) candyVec[i] = max(candyVec[i], candyVec[i+1] + 1);
        }

        int sum = 0;
        for(int i = 0; i < candyVec.size(); i++) {
            sum += candyVec[i];
        }
        return sum;
    }
};
```

## 92 柠檬水找零

[860. 柠檬水找零 - 力扣（LeetCode）](https://leetcode.cn/problems/lemonade-change/submissions/680941753/)

```C++
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill: bills) {
            if (bill == 5) five++;
            if (bill == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            if (bill == 20) {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                    twenty++;
                } else if (five >= 3) {
                    five -= 3;
                    twenty++;
                } else return false;
            }
        }
        return true;
    }
};
```

## 93 根据身高重建队列

[406. 根据身高重建队列 - 力扣（LeetCode）](https://leetcode.cn/problems/queue-reconstruction-by-height/)

```C++
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};
```

## 94 用最少数量的箭引爆气球

[452. 用最少数量的箭引爆气球 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/submissions/680949677/)

```C++
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        
        int res = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i-1][0]) res++;
            else points[i][1] = min(points[i - 1][1], points[i][1]); 
        }
        return res;
    }
};
```

# 2025/11/27

## 95 无重叠区间

[435. 无重叠区间 - 力扣（LeetCode）](https://leetcode.cn/problems/non-overlapping-intervals/description/)

```C++
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
```

## 96 划分字母区间

[763. 划分字母区间 - 力扣（LeetCode）](https://leetcode.cn/problems/partition-labels/submissions/)

```C++
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
```

## 97 合并区间

[56. 合并区间 - 力扣（LeetCode）](https://leetcode.cn/problems/merge-intervals/submissions/681048333/)

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
```

## 98 单调递增的数字

[738. 单调递增的数字 - 力扣（LeetCode）](https://leetcode.cn/problems/monotone-increasing-digits/description/)

```C++
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i-1] > strNum[i]) {
                flag = i;
                strNum[i-1]--;
            }
        }
        
        for (int i = flag; i < strNum.size(); i++) 
            strNum[i] = '9';
        return stoi(strNum);
    }
};
```

## 99 监控二叉树

[968. 监控二叉树 - 力扣（LeetCode）](https://leetcode.cn/problems/binary-tree-cameras/description/)

```C++
class Solution {
public:
    int count;
    int traversal(TreeNode* cur) {
        if (cur == nullptr) return 2;

        int left = traversal(cur->left);
        int right = traversal(cur->right);

        if (left == 2 && right == 2) return 0;
        if (left == 0 || right == 0) {
            count++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        count = 0;
        if (traversal(root) == 0) count++;
        return count;
    }
};
```

