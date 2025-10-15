/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=
 *
 * [1658] 将 x 减到 0 的最小操作数
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
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int right = 0;
        int len = -1;
        int target = 0;
        for (int num : nums) {
            target += num;
        }
        target -= x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            right++;
            
            while (sum >= target && left < right) {
                if (sum == target) {
                    len = max(len, right - left);
                }
                sum -= nums[left];
                left++;
            }
        }

        return len == -1 ? -1 : nums.size() - len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v{1,1};
    solution.minOperations(v, 2);
}



/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */

