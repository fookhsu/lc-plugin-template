/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=
 *
 * [525] 连续数组
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int preSum = 0;
        int res = 0;
        unordered_map<int, int> vToIdx;
        // 前i个前缀和 个数i
        vToIdx[preSum] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            preSum = preSum + (nums[i - 1] == 0 ? -1 : 1);
            if (vToIdx.find(preSum) == vToIdx.end()) {
                vToIdx[preSum] = i;
            } else {

                res = max(res, i - vToIdx[preSum]);
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v{0,1};
    solution.findMaxLength(v);
}



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,1,1,0,0,0]\n
// @lcpr case=end

 */

