/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=
 *
 * [25] K 个一组翻转链表
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

    //     ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (head == nullptr) return nullptr;
    //     // 区间 [a, b) 包含 k 个待反转元素
    //     ListNode *a, *b;
    //     a = b = head;
    //     for (int i = 0; i < k; i++) {
    //         // 不足 k 个，不需要反转了
    //         if (b == nullptr) return head;
    //         b = b->next;
    //     }
    //     // 反转前 k 个元素
    //     ListNode *newHead = reverseN(a, k);
    //     // 此时 b 指向下一组待反转的头结点
    //     // 递归反转后续链表并连接起来
    //     a->next = reverseKGroup(b, k);
    //     return newHead;
    // }

    // // 上文实现的反转前 N 个节点的函数
    // ListNode* reverseN(ListNode* head, int n) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }
    //     ListNode *pre, *cur, *nxt;
    //     pre = nullptr; cur = head; nxt = head->next;
    //     while (n > 0) {
    //         cur->next = pre;
    //         pre = cur;
    //         cur = nxt;
    //         if (nxt != nullptr) {
    //             nxt = nxt->next;
    //         }
    //         n--;
    //     }
    //     head->next = cur;
    //     return pre;

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = head;
        int step = k;
        while (p != nullptr && step > 0) {
            p = p->next;
            step--;
        }
        // 表示本链表节点数小于k 不需要反转
        if (step >= 1) {
            return head;
        }
        step = k;
        ListNode *pre = nullptr, *cur = head, *nxt = head->next;
        while (step > 0) {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            step--;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
        }

        head->next = reverseKGroup(p, k);
        
        return pre;
    }
};

// @lc code=end

int main() {
    Solution solution;
    ListNode *head = ListNode::createHead({1, 2, 3, 4, 5});
    solution.reverseKGroup(head, 3);
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

