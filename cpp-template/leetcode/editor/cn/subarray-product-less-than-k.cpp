/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int product = 1;
        while (right < nums.size()) {
            product *= nums[right];
            right++;
            
            while (left < right && product >= k) {
                product /= nums[left];
                left++;
            }
            // 元素个数 用迭代方式考虑，假设原来数组为空，新加入一个元素计入统计，同时子数组为1
            // 等到right扩大时候，仅仅需要考虑多增加的元素和原来的数组的组合，即[left+1, right) ... [right, right)
            // 一共 right - left 个数元素（原来数组个数）， 所以每次迭代更新
            // 同样考虑left左边界缩小的情况，是因为新增了一个元素后乘积扩大导致，所以移动后的left仅需要考虑和新增元素的组合
            // 同样是right - left 个数元素
            count += right - left;
        }

        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

