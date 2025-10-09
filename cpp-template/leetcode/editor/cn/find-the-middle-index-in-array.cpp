/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 * @lcpr version=
 *
 * [1991] 找到数组的中间位置
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> sum;
public:
    int findMiddleIndex(vector<int>& nums) {
        sum.resize(nums.size() + 1, 0);
        // sum[i] --> sum[0, i - 1]
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = nums[i - 1] + sum[i - 1];
        }
        int total = sum[sum.size() - 1];
        for (int i = 1; i < sum.size(); i++) {
            // 中间位置 i - 1 
            if (sum[i - 1] == total - sum[i]) {
                return i - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,3,-1,8,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

