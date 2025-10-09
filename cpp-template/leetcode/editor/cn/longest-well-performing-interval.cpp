/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 * @lcpr version=
 *
 * [1124] 表现良好的最长时间段
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
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int preSum = 0;
        unordered_map<int, int> stat;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            preSum += (hours[i - 1] > 8 ? 1 : -1);
            // 记录第一次 使索引最小
            if (stat.find(preSum) == stat.end()) {
                stat[preSum] = i;
            }
            if (preSum > 0) {
                res = max(res, i);
            } else {
                if (stat.find(preSum - 1) != stat.end()) {
                    res = max(res, i - stat[preSum - 1]);
                }
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
// [9,9,6,0,6,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

 */

