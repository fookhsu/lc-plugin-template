/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=30203
 *
 * [162] 寻找峰值
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
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int lv = mid - 1 < 0 ? INT_MIN : nums[mid - 1];
            int rv = mid + 1 == nums.size() ? INT_MIN : nums[mid + 1];
            if (lv > nums[mid]) {
                right = mid;
            } else if (rv > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return left;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v{1,2,3,1};
    solution.findPeakElement(v);
}



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */

