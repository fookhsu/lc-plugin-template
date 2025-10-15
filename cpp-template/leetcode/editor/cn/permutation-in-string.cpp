/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=
 *
 * [567] 字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> windows, stat;
        for (char c : s1) {
            stat[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (stat.count(c)) {
                windows[c]++;
                if (stat[c] == windows[c]) {
                    valid++;
                }
            }
            if (right - left == s1.size()) {
                if (valid == stat.size()) {
                    return true;
                }
                char c = s2[left];
                left++;
                if (stat.count(c)) {
                    if (stat[c] == windows[c]) {
                        valid--;
                    }
                    windows[c]--;
                } 
            }
        }
        
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */

