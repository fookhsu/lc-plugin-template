/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30203
 *
 * [875] 爱吃香蕉的珂珂
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000'000'000 + 1; // 1 <= piles[i] <= 10^9
        // h关于k单调减 取左边界
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int hours = calHours(piles, mid);
            if (hours == h) {
                right = mid; // 搜索左侧
            } else if (hours < h) {
                right = mid;
            } else if (hours > h) {
                left = mid + 1;
            }
        }
        
        return left;
    }
private:
    int calHours(vector<int>& piles, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
        }
        return hours;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

