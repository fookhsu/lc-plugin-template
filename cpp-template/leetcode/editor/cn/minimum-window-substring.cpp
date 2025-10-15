/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        unordered_map<int, int> windows, stat;
        for (char c: t) {
            stat[c]++;
        }
        int valid = 0; // 统计窗口中的符号字符数
        int left = 0;
        int right = 0;
        int start = left;
        int len = INT_MAX;
        while (right < s.size()) { 
            char c = s[right];
            right++;
            if (stat.count(c)) {
                windows[c]++;
                if (stat[c] == windows[c]) {
                    valid++;
                }
            }

            while (valid == stat.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
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

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "bba";
    string t = "ab";
    solution.minWindow(s, t);

}



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

