/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int, int> windows, stat;
        vector<int> res;
        int left = 0;
        int right = 0;
        int valid = 0;
        for (char c : p) {
            stat[c]++;
        }

        while (right < s.size()) {
            char c = s[right];
            right++;
            if (stat.count(c)) {
                windows[c]++;
                if (stat[c] == windows[c]) {
                    valid++;
                }
            }

            if (right - left == p.size()) {
                if (valid == stat.size()) {
                    res.push_back(left);
                }
                char c = s[left];
                left++;
                if (stat.count(c)) {
                    if (stat[c] == windows[c]) {
                        valid--;
                    }
                    windows[c]--;
                }
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
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

