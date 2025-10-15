/*
 * @lc app=leetcode.cn id=424 lang=cpp
 * @lcpr version=
 *
 * [424] 替换后的最长重复字符
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
    int characterReplacement(string s, int k) {
        vector<int> alphaCount(26, 0);
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int len = 0;
        while (right < s.size()) {
            int i = s[right] - 'A';
            alphaCount[i]++;
            maxCount = max(maxCount, alphaCount[i]);
            right++;
            // 这里无需对maxCount处理，分类讨论后就显而易见了
            while (right - left - maxCount > k) {
                int i = s[left] - 'A';
                alphaCount[i]--;
                left++;
            }

            len = max(right - left, len);
        }

        return len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "ABAB"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AABABBA"\n1\n
// @lcpr case=end

 */

