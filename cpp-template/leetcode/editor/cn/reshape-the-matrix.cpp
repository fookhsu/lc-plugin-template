/*
 * @lc app=leetcode.cn id=566 lang=cpp
 * @lcpr version=30203
 *
 * [566] 重塑矩阵
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < m * n; i++) {
            set(res, i, get(mat, i));
        }

        return res;
    }

private:
    int get(vector<vector<int>> &mat, int i)
    {
        int n = mat[0].size();
        return mat[i / n][i % n];
    }
    void set(vector<vector<int>> &mat, int i, int v)
    {
        int n = mat[0].size();
        mat[i / n][i % n] = v;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1;
    int c = 4;
    solution.matrixReshape(mat, 1, 4);
}

/*
// @lcpr case=start
// [[1,2],[3,4]]\n1\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n2\n4\n
// @lcpr case=end

 */
