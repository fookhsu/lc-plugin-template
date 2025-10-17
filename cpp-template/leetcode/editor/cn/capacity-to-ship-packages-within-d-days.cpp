/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=30203
 *
 * [1011] 在 D 天内送达包裹的能力
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
    int shipWithinDays(vector<int>& weights, int days) {
        // weight货物包裹必须整体运送 必须按顺序运送
        // 给定weights days 是关于船舶的单调减
        int left = 1;
        // 1 <= days <= weights.length <= 5 * 104
        // 1 <= weights[i] <= 500
        int right = 25'000'000 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int d = calDays(weights, mid);
            if (d == days) {
                right = mid; // 右侧左移 搜索左侧
            } else if (d < days) {
                right = mid;
            } else if (d > days) {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    int calDays(vector<int>& weights, int c) {
        int days = 0;
        int t = c;
        for (int weight : weights) {
            if (weight > c) {
                return INT_MAX; // 运载能力太小，无法完成
            }
            if (t < weight) {
                days++;
                t = c;
            }
            t -= weight;
        }
        days++;
        return days;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> w{3, 2, 2, 4, 1, 4};
    int d = 3;
    solution.shipWithinDays(w, d);
}



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */

