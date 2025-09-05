/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for (int col = 0; col < str.size(); col++) {
            for (int row = 1; row < strs.size(); row++) {
                if (strs[row].size() < col || strs[row - 1].size() < col || 
                    strs[row - 1][col] != strs[row][col]) {
                        return str.substr(0, col);
                    }
            }
        }

        return str;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

