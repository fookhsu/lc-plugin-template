/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int p0, p1, p2;
        p0 = p1 = 0;
        p2 = nums.size() - 1;
        int tmp;
        while (p1 <= p2) { // p0 p2索引所在元素未经核查
            if (nums[p1] == 0) {
                tmp = nums[p0];
                nums[p0++] = 0;
                nums[p1] = tmp;
            } else if (nums[p1] == 2) {
                tmp = nums[p2];
                nums[p2--] = 2;
                nums[p1] = tmp;
            } else {
                p1++;
            }
            // 这里扫描指针p1有可能走的比p0慢 这时需要移动指针
            if (p1 < p0) {
                p1 = p0;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v = {2, 0, 2, 1, 1, 0};
    solution.sortColors(v);
    // your test code here
}



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

