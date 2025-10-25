/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=30203
 *
 * [658] 找到 K 个最接近的元素
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int p = findTarget(arr, x);
        int left = p - 1, right = p;
        while (right - left - 1 < k) { // (left, right)
            if (left < 0) {
                right++;
            } else if (right == arr.size()) {
                left--;
            } else if (arr[right] - x >= x - arr[left]) {
                left--;
            } else {
                right++;
            }
        }
        vector<int> res;
        for (int i = left + 1; i < right; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
private:
    int findTarget(vector<int>& arr, int t) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == t) {
                right = mid;
            } else if (arr[mid] < t) {
                left = mid + 1;
            } else if (arr[mid] > t) {
                right = mid;
            }
        }

        return left;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */

