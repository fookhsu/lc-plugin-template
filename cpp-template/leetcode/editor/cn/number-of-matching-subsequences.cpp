/*
 * @lc app=leetcode.cn id=792 lang=cpp
 * @lcpr version=30203
 *
 * [792] 匹配子序列的单词数
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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> chMap(26);
        for (int i = 0; i < s.size(); i++) {
            chMap[s[i] - 'a'].push_back(i);
        }
        int count = 0;

        for (string word : words) {
            int i = 0; // word
            int j = 0; // s
            while (i < word.size()) {
                int ch = word[i] - 'a';
                if (chMap[ch].empty()) {
                    break;
                }
                int idx = findCh(chMap[ch], j);
                
                if (idx == chMap[ch].size()) {
                    break;
                }
                j = chMap[ch][idx];

                i++;
                j++;
            }

            if (i == word.size()) {
                count++;
            }
        }

        return count;
    }

private:
    int findCh(vector<int>& v, int i) {
        int left = 0;
        int right = v.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == i) {
                right = mid;
            } else if (v[mid] < i) {
                left = mid + 1;
            } else if (v[mid] > i) {
                right = mid;
            }
        }

        return left;
    }
};
// @lc code=end

int main() {
    Solution solution;
    string s = "btovxbkumc";
    vector<string> words = {"btovxbku","to","zueoxxxjme","yjkclbkbtl"};
    solution.numMatchingSubseq(s, words);
}



/*
// @lcpr case=start
// "abcde"\n["a","bb","acd","ace"]\n
// @lcpr case=end

// @lcpr case=start
// "dsahjpjauf"\n["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]\n
// @lcpr case=end

 */

