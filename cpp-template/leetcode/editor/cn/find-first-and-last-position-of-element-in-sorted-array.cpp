/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        if (left == -1) {
            return {-1, -1};
        }
        int right = right_bound(nums, target);

        return {left, right};
    }
private:
    int left_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] == target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            }
        }
        if (l == nums.size()) {
            return -1;
        }
        return nums[l] == target ? l : -1; 
    }

    int right_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] == target) {
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            }
        }
        if (l - 1 < 0) {
            return -1;
        }
        return nums[l - 1] == target ? (l - 1) : -1; 
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

