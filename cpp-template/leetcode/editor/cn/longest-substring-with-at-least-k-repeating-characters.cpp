/*
 * @lc app=leetcode.cn id=395 lang=cpp
 * @lcpr version=
 *
 * [395] 至少有 K 个重复字符的最长子串
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
    int longestSubstring(string s, int k) {
        int len = 0;
        for (int i = 1; i <= 26; i++) {
            int left = 0;
            int right = 0;
            int valid = 0; // 计算子串内字符种类个数
            int types = 0;
            vector<int> alphaCount(26, 0);
            while (right < s.size()) {
                int e = s[right] - 'a';
                if (alphaCount[e] == 0) {
                    types++;
                }
                alphaCount[e]++;
                if (alphaCount[e] == k) {
                    valid++;
                }
                right++;

                while (types > i) {
                    e = s[left] - 'a';
                    if (alphaCount[e] == k) {
                        valid--;
                    }
                    alphaCount[e]--;
                    if (alphaCount[e] == 0) {
                        types--;
                    }

                    left++;
                }
                // 只有符合i种时才更新
                if (valid == i) {
                    len = max(len, right - left);
                }
            }
        }

        return len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    string s = "ababbc";
    int k = 2;
    solution.longestSubstring(s, k);
}



/*
// @lcpr case=start
// "aaabb"\n3\n
// @lcpr case=end

// @lcpr case=start
// "ababbc"\n2\n
// @lcpr case=end

 */

