/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=
 *
 * [1260] 二维网格迁移
 */

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    // 观察矩阵 从左到右在移动之后 只是第一行回环移动了，因此把二维数组转换成一维数组
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        deque<int> dq = grid2Arrary(grid);
        while (k > 0) {
            int val = dq.back();
            dq.push_front(val);
            dq.pop_back();
            k--;
        }

        vector<vector<int>> res = arrary2Grid(dq, grid.size(), grid[0].size());

        return res;
    }
private:
    deque<int> grid2Arrary(const vector<vector<int>>& grid) {
        deque<int> dq;
        for (const auto &row : grid) {
            for (int value : row) {
                dq.push_back(value);
            }
        }

        return dq;
    }

    vector<vector<int>> arrary2Grid(const deque<int>& dq, int m, int n) {
        vector<vector<int>> grid;
        for (int i = 0; i < m; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                v.push_back(dq[i * n + j]);
            }
            grid.push_back(v);
        }

        return grid;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> v = {{1}, {2}, {3},{4},{7},{6},{5}};
    solution.shiftGrid(v, 23);
    // your test code here
}



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */

