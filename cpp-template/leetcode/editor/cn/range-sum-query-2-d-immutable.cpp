/*
 * @lc app=leetcode.cn id=304 lang=cpp
 * @lcpr version=
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class NumMatrix {

vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m * n == 0) return;
        sum.resize(m + 1, vector<int>(n + 1, 0));
        // sum[i][j] (0,0) --> (i - 1, j - 1)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // (row2, col2) - (row2, col1 - 1) - (row1 - 1, col2) + (row1 - 1, col1 - 1)
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1 ][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({3,0,1,4,2});
    matrix.push_back({5,6,3,2,1});
    matrix.push_back({1,2,0,1,5});
    matrix.push_back({4,1,0,1,7});
    matrix.push_back({1,0,3,0,5});
    NumMatrix num(matrix);
    int ret = num.sumRegion(2,1,4,3);
}



/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */

