/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        string res = "", res1, res2;
        for (int i = 0; i < s.length(); i++) {
            res1 = palindrome(s, i, i);
            res2 = palindrome(s, i, i + 1);
            res = res1.length() > res.length() ? res1 : res;
            res = res2.length() > res.length() ? res2 : res;
        }

        return res;
    }

private:
    string palindrome(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }

};

// @lc code=end

int main() {
    Solution solution;
    string s = "abad";
    solution.longestPalindrome(s);
    // your test code here
}



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

