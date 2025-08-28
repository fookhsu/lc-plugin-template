/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=
 *
 * [206] 反转链表
 */

#include <iostream>
#include <vector>
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
    // 迭代法
    ListNode* reverseList1(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = head;
        nxt = head->next;
        while (cur != nullptr) {
            // 只有cur pre执行反转 nxt 其实是个临时存放下一节点指针
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }

        return pre;
    }
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

