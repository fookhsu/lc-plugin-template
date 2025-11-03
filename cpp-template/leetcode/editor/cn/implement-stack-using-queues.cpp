/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=
 *
 * [225] 用队列实现栈
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyStack {
private:
    queue<int> q;
    int e;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        e = x;
    }
    
    int pop() {
        int n = q.size();
        while (n > 1) {
            e = q.front();
            q.push(q.front());
            q.pop();
            n--;
        }
        int res = q.front();
        q.pop();

        return res;
    }
    
    int top() {
        return e;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    // Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

