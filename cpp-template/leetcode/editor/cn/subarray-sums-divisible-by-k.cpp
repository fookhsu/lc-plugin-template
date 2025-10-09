/*
 * @lc app=leetcode.cn id=974 lang=cpp
 * @lcpr version=
 *
 * [974] 和可被 K 整除的子数组
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
    int subarraysDivByK(vector<int>& nums, int k) {
        int preSum = 0;
        int res = 0;
        // reminder : count
        unordered_map<int, int> stat;
        stat[0] = 1;
        int reminder = 1;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            reminder = preSum % k;
            if (reminder < 0) {
                reminder += k;
            }
            if (stat.find(reminder) != stat.end()) {
                res += stat[reminder];
                stat[reminder]++;
            } else {
                stat[reminder] = 1;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [4,5,0,-2,-3,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n9\n
// @lcpr case=end

 */

