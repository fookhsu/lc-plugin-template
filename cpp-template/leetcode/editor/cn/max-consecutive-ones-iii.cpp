/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=
 *
 * [1004] 最大连续1的个数 III
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
    // int longestOnes(vector<int>& nums, int k) {
    //     int left = 0;
    //     int right = 0;
    //     int len = 0;
    //     while (right < nums.size()) {
    //         while (k >= 0 && right < nums.size()) {
    //             int e = nums[right];
    //             right++;
    //             if (e == 0) {
    //                 k--;
    //             }
    //         }
    //         int size = right - left;
    //         if (k < 0) {
    //             size--;
    //         }
    //         len = max(len, size);
            
    //         while (k < 0 && left < right) {
    //             int e = nums[left];
    //             left++;
    //             if (e == 0) {
    //                 k++;
    //             }
    //         }
    //     }

    //     return len;
    // }
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int len = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                k--;
            }

            right++;

            while (k < 0) {
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }
            len = max(len, right - left);
        }

        return len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */

