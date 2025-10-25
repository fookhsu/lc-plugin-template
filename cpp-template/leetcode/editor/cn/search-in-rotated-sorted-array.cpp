/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30203
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        // 开区间的前提是right不参与数组 这里用闭区间
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 这里是为了方便排除后面mid 因为这里是<=条件跳出循环
            if (target == nums[mid])
            {
                return mid;
            }
            // 都在同一递增数组内
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    solution.search(v, 0);
}

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
