/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=30300
 *
 * [81] 搜索旋转排序数组 II
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            // // 快速收缩
            // if (nums[left] == nums[mid] && left != mid)
            // {
            //     left = mid;
            //     continue;
            // }
            if (nums[mid] > nums[left])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < nums[left])
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {           // nums[left] == nums[mid] 无法确定mid在哪边
                left++; // 因为nums[mid] != target
                if (nums[right] == nums[mid])
                {
                    right--;
                }
                else if (nums[right] > nums[mid]) // 未截断
                {
                    left = mid + 1;
                    if (target > nums[right])
                    {
                        return false;
                    }
                }
                else // mid 在截断两个区间的左侧
                {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> v = {2, 5, 6, 0, 0, 1, 2};
    int t = 3;
    solution.search(v, t);
}

/*
// @lcpr case=start
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */
