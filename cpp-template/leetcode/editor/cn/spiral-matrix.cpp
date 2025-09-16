/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int upper_bound = 0;
        int left_bound = 0;
        int lower_bound = matrix.size() - 1;
        int right_bound = matrix[0].size() - 1;
        vector<int> res;
        while (upper_bound <= right_bound && left_bound <= right_bound) {
            // up
            for (int i = left_bound; i <= right_bound; i++) {
                res.push_back(matrix[upper_bound][i]);
            }
            upper_bound++;
            if (upper_bound > lower_bound) {
                break;
            }
            // right
            for (int j = upper_bound; j<= lower_bound; j++) {
                res.push_back(matrix[j][right_bound]);
            }
            right_bound--;
            if (left_bound > right_bound) {
                break;
            }
            // down
            for (int i = right_bound; i >= left_bound; i--) {
                res.push_back(matrix[lower_bound][i]);
            }
            lower_bound--;
            if (upper_bound > lower_bound) {
                break;
            }
            // left
            for (int j = lower_bound; j >= upper_bound; j--) {
                res.push_back(matrix[j][left_bound]);
            }
            left_bound++;
        }
        return res;
        // up right down left 
        // 0 3 2 0 // 1 3 2 0 // 1 2 2 0 // 1 1 2 0 // 1 1 2 1 // 2 1 2 1
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> v;
    v.push_back({1,2,3,4});
    v.push_back({5,6,7,8});
    v.push_back({9,10,11,12});
    solution.spiralOrder(v);
}



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

