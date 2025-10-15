/*
 * @lc app=leetcode.cn id=187 lang=cpp
 * @lcpr version=
 *
 * [187] 重复的DNA序列
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<int> v(s.size());

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'A':
                v[i] = 0;
                break;
                case 'C':
                v[i] = 1;
                break;
                case 'G':
                v[i] = 2;
                break;
                case 'T':
                v[i] = 3;
            }
        }
        // 4进制
        int R = 4;
        int L = 10;
        int RL = (int)pow(4, 10 - 1);
        unordered_set<int> seen;
        // vector<string> res; 这里用哈希表存储防止重复
        unordered_set<string> res;
        int left = 0;
        int right = 0;
        int hash = 0;
        while (right < s.size()) {
            hash = R * hash + v[right];
            right++;
            if (right - left == 10) {
                if (seen.find(hash) == seen.end()) {
                    seen.insert(hash);
                } else {
                    res.insert(s.substr(left, L));
                }
                hash -= v[left] * RL;
                left++;
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"\n
// @lcpr case=end

// @lcpr case=start
// "AAAAAAAAAAAAA"\n
// @lcpr case=end

 */

