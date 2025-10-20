/*
 * @lc app=leetcode.cn id=240 lang=cpp
 * @lcpr version=30203
 *
 * [240] 搜索二维矩阵 II
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 每行的元素从左到右升序排列。
        // 每列的元素从上到下升序排列
        // 如果想使用二分搜索，前提是一侧元素比本元素小，另一侧比本元素大
        // 如果从右上角出发，则左侧为小，下方为大
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i <m && j >= 0) {
            int v = matrix[i][j];
            if (v == target) {
                return true;
            } else if (v < target) {
                i++;
            } else if (v > target) {
                j--;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> m{{1,1}};
    int t = 0;
    solution.searchMatrix(m ,t);
}



/*
// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
// @lcpr case=end

 */

