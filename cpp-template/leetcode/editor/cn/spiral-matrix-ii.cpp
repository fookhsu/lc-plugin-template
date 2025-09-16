/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=
 *
 * [59] 螺旋矩阵 II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0;
        int left = 0;
        int right = n - 1;
        int down = n - 1;
        int e = 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                res[up][i] = e++;
            }
            up++;
            if (up > down) {
                break;
            }
            for (int j = up; j <= down; j++) {
                res[j][right] = e++;
            }
            right--;
            if (left > right) {
                break;
            }
            for (int i = right; i >= left; i--) {
                res[down][i] = e++;
            }
            down--;
            if (up > down) {
                break;
            }
            for (int j = down; j >= up; j--) {
                res[j][left] = e++;
            }
            left++;
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
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

