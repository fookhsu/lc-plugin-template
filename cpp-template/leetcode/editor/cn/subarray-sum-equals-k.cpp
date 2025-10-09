/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> stat;
        vector<int> preSum(n + 1, 0);
        stat[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            int target = preSum[i] - k;
            if (stat.find(target) != stat.end()) {
                res += stat[target];
            }
            stat[preSum[i]]++;
        }

        return res; 
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v{1};
    solution.subarraySum(v,1);
}



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

