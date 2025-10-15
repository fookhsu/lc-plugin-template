/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=
 *
 * [219] 存在重复元素 II
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> windows;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            int n = nums[right];
            right++;
            if (windows.find(n) != windows.end()) {
                return true;
            } 
            
            windows.insert(n);

            if (right - left > k) {
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
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */

