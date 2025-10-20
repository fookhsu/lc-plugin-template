/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30203
 *
 * [74] 搜索二维矩阵
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0;
        int right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int v = get(matrix, mid);
            if (v == target) {
                return true;
            } else if (v < target) {
                left = mid + 1;
            } else if (v > target) {
                right = mid;
            }
        }

        return false;
    }

private:
    int get(vector<vector<int>> &mat, int i)
    {
        int n = mat[0].size();
        return mat[i / n][i % n];
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */
