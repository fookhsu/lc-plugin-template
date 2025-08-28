/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=
 *
 * [378] 有序矩阵中第 K 小的元素
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>&b){ return a[0] > b[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < matrix.size();i++) {
            pq.push({matrix[i][0], i, 0});
        }
        int res = 0;
        while(!pq.empty() && k > 0) {
            vector<int> v = pq.top();
            pq.pop();
            k--;
            res = v[0];
            int i = v[1];
            int j = v[2];
            if (j + 1 < matrix.size()) {
                pq.push({matrix[i][j+1], i, j+1});
            }
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
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */

