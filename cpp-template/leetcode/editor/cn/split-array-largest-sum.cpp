/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30203
 *
 * [410] 分割数组的最大值
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
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        right++;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            int n = calNums(nums, mid);
            if (n == k) {
                right = mid;
            } else if (n < k) {
                right = mid;
            } else if (n > k) {
                left = mid + 1;
            }
        }

        return left;
    }
private:
    int calNums(vector<int>& nums, int c) {
        int n = 0;
        int t = c;
        for (int num : nums) {
            if (num > c) {
                return INT_MAX;
            }
            if (t < num) {
                t = c;
                n++;
            }
            t -= num;
        }
        n++;

        return n;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v{7, 2, 5, 10, 8};
    int k = 2;
    solution.splitArray(v, k);
}



/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */

