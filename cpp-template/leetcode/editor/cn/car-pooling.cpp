/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=
 *
 * [1094] 拼车
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for (auto & trip : trips) {
            // [i, j)
            diff[trip[1]] += trip[0];
            if (trip[2] < 1001) {
                diff[trip[2]] -= trip[0];
            }
        }
        vector<int> stat(1001,0);
        stat[0] = diff[0];
        if (stat[0] > capacity) {
            return false;
        }
        for (int i = 1; i < stat.size(); i++) {
            stat[i] = stat[i - 1] + diff[i];
            if (stat[i] > capacity) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

