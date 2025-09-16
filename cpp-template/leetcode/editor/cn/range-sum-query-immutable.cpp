/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=
 *
 * [303] 区域和检索 - 数组不可变
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class NumArray {
vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1);
        // preSum [0, i - 1]
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> v{1,2};
    NumArray arr(v);
    // your test code here
}



/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"]\n[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */

