/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=
 *
 * [220] 存在重复元素 III
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> windows;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            // 找到第一个不小于nums[right]的位置
            auto it = windows.lower_bound(nums[right]);
            if (it != windows.end() && *it - nums[right] <= valueDiff) {
                return true;
            }
            if (it != windows.begin()) {
                --it; // 最接近nums[right]且小于它的位置
                if (nums[right] - *it <= valueDiff) {
                    return true;
                }
            }

            windows.insert(nums[right]);
            right++;
            
            if (right - left > indexDiff) {
                windows.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */

