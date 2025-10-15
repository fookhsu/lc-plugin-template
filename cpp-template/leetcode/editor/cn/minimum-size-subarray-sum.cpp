/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            right++;
            while (sum >= target) {
                len = min(len, right - left);
                sum -= nums[left];
                left++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

