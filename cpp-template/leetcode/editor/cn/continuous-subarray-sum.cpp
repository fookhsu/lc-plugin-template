/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * @lcpr version=
 *
 * [523] 连续的子数组和
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        // (preSum[i] - preSum[j]) % k == 0 
        // --> preSum[i] % k == preSum[j] % k
        unordered_map<int, int> m;
        m[0] = 0;
        for (int i = 1; i < preSum.size(); i++) {
            if (m.find(preSum[i] % k) == m.end()) {
                m[preSum[i] % k] = i;
            } else if ((i - m[preSum[i] % k]) >= 2){
                return true;
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
// [23,2,4,6,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n13\n
// @lcpr case=end

 */

