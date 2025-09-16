/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=
 *
 * [48] 旋转图像
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
    /// @brief 顺时针旋转90度之后第一行变成了最后一列、第二行变成了倒数第二列
    /// 对应操作就是 行--》列 第一列变成倒数第一列
    /// @param matrix N*N
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 下三角
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

