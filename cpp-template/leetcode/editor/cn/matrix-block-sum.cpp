/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 * @lcpr version=
 *
 * [1314] 矩阵区域和
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> preSum;
    int calSum(int i, int j, int k) {
        int m = preSum.size() - 1;
        int n = preSum[0].size() - 1; 
        int row1 = max(0, i - k);
        int row2 = min(m - 1, i + k);
        int col1 = max(0, j - k);
        int col2 = min(n - 1, j + k);
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }

public:
    // 这题就是 [304] 二维区域和检索 - 矩阵不可变 变种 区别是点需要取min max
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        preSum.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                preSum[i][j] = mat[i - 1][j - 1] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
            }
        }

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = calSum(i, j, k);
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> v;
    v.push_back({1,2,3});
    v.push_back({4,5,6});
    v.push_back({7,8,9});
    /*
      1 2 3
      4 5 6
      7 8 9
      --》preSum
      1 3 6
      5 12 21
      12 27 45
      --> k = 1 expected
      12 21 16
      27 45 33
      24 39 28
     */
    auto res = solution.matrixBlockSum(v, 1);
}



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n2\n
// @lcpr case=end

 */

