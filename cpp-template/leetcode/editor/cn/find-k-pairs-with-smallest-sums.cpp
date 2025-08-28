/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=
 *
 * [373] 查找和最小的 K 对数字
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
    vector<vector<int>> wrongKSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // a11 (a12,a21) --> (a12/a21, a22, a13,a31, a14 a41 ...)
        auto cmp = [](const vector<int>& a, const vector<int>& b){return (a[0] + a[1]) > (b[0] + b[1]);};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        // 把nums1每个元素摘出来，和num2元素搭配 形成nums1.size数量个升序vector
        // 问题转化为x个升序vector合并问题 假定nums1 size为m nums2 size为n 共有n个vector 一次取每个加入
        int index = 0;
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i], nums2[index]});
        }
        index++;
        vector<vector<int>> res;
        while(!pq.empty() && k >0) {
            res.push_back(pq.top());
            pq.pop();
            k--;
            // !!! 这种解法的错误在于如果k非常大超过了 num2 的size后续的结果就放不进去，
            // 并且一直添加的是第一个vector 其他vector没有考虑这个解法错误
            // 所以后续添加的元素不需要是剩余元素中的最小的
            // 因为如果其不是最小的，那么必然存在已加入的元素组合中会被提前pop，它之后的元素也会加入
            if (index < nums2.size()) {
                pq.push({nums1[0], nums2[index]});
                index++;
            }
        }
        return res;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){return (a[0] + a[1]) > (b[0] + b[1]);};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        // 把nums1每个元素摘出来，和num2元素搭配 形成nums1.size数量个升序vector
        // 问题转化为x个升序vector合并问题 假定nums1 size为m nums2 size为n 共有n个vector 一次取每个加入
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while(!pq.empty() && k >0) {
            vector tmp = pq.top();
            res.push_back({tmp[0],tmp[1]});
            int next_index = tmp[2] + 1;
            pq.pop();
            k--;
            // 后续添加的元素不需要是剩余元素中的最小的
            // 因为如果其不是最小的，那么必然存在已加入的元素组合中会被提前pop，它之后的元素也会加入
            if (next_index < nums2.size()) {
                pq.push({tmp[0], nums2[next_index], next_index});
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v1 = {1,2,4,5,6};
    vector<int> v2 = {3,5,7,9};
    auto res = solution.kSmallestPairs(v1, v2, 3);
    // your test code here
}



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */

