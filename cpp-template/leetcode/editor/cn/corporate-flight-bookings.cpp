/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 * @lcpr version=
 *
 * [1109] 航班预订统计
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        Helper h(n);
        for (auto & booking : bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            h.incremental(i, j, val);
        }
        
        return h.result();
    }
    class Helper {
    vector<int> diff;
    public:
    Helper(int n) {
        diff.resize(n,0);
    }

    void incremental(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < res.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }

        return res;
    }
};
};


// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */

