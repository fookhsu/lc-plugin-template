/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=
 *
 * [977] 有序数组的平方
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
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针合并排序 既可能两边大中间小 也可能单调 所以需要三个指针
        // 从大到小合并
        int i = 0;
        int j = nums.size() - 1;
        int p = j;
        vector<int> res(nums.size()); // 从大到小填充
        while (i <= j) { // 等于是为了最后一个元素压入
            if (abs(nums[i]) < abs(nums[j])) {
                res[p] = nums[j] * nums[j];
                j--;
            } else {
                res[p] = nums[i] * nums[i];
                i++;
            }
            p--;
        }

        return res;
    }
private:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

