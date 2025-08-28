/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=
 *
 * [445] 两数相加 II
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 != nullptr) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        int flag = 0;
        int val = 0;
        ListNode* dummy = new ListNode(-1);
        while (!s1.empty() || !s2.empty()) {
            val = 0;
            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }
            val += flag;
            flag = val / 10;
            val %= 10;
            ListNode *tmp = dummy->next;
            dummy->next = new ListNode(val);
            dummy->next->next = tmp;
        }
        if (flag != 0) {
            ListNode *tmp = dummy->next;
            dummy->next = new ListNode(flag);
            dummy->next->next = tmp;
        }

        return dummy->next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

