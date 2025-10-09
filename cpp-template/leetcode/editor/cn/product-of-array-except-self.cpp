/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=
 *
 * [238] 除自身以外数组的乘积
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    // 除了nums[i]自身外的乘积 可以分为左侧和右侧乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        // 计算元素左侧乘积
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // 计算元素右侧乘积
        int rp = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= rp;
            rp *= nums[i];
        }
        
        return answer;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

