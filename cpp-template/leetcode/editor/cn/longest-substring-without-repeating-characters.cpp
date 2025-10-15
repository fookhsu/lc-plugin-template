/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> stat;
        int left = 0;
        int right = 0;
        int len = 0;
        while (right < s.size()) {
            char c = s[right];
            stat[c]++;
            right++; // [left, right)
            if (stat[c] == 1) {
                len = max(right - left, len);
            }
            while (stat[c] > 1) {
                char h = s[left];
                stat[h]--;
                left++;
            }
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
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

