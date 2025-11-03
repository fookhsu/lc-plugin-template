/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyQueue {
private:
stack<int> s1;
stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int e = s1.top();
                s2.push(e);
                s1.pop();
            }
        }
        int e = s2.top();
        s2.pop();
        return e;
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        } else {
                while (!s1.empty()) {
                    int e = s1.top();
                    s2.push(e);
                    s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    // your test code here
}



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

