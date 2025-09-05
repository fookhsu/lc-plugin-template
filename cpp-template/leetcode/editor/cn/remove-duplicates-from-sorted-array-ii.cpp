/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int>& nums) {
        int slow{0}, fast{0}, flag{0};
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast++];
                flag = 0;
            } else if (flag < 1 && slow != fast) {
                slow++;
                nums[slow] = nums[fast++];
                flag++;
            } else {
                fast++;
            }
        }

        return slow + 1;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

