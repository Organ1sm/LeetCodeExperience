//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 967 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            if (nums.empty())
            { return vector<int>{-1, -1}; }

            auto firstPos = findFirstPos(nums, target);
            if (firstPos == -1)
            { return vector<int>{-1, -1}; }

            auto lastPos = findLastPos(nums, target);
            return vector<int>{firstPos, lastPos};
        }

        int findFirstPos(vector<int> &nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;

            while(left <= right)
            {
                int mid = (left + right) / 2;
                // 因为找第一个出现的位置，所以即使找到也要一直往右边找，
                if (nums[mid] >= target)
                { right = mid - 1; }
                else
                { left = mid + 1; }
            }

            if (left != nums.size() && nums[left] == target)
            {
                return left;
            }
            return -1;
        }

        int findLastPos(vector<int> &nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;

            while(left <= right)
            {
                int mid = (left + right) / 2;

                if (nums[mid] <= target)
                { left = mid + 1; }
                else
                { right = mid - 1; }
            }

            return right;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{5, 7, 7, 8, 8};
    s.searchRange(data, 8);

    cout << "Hello LeetCode" << endl;
}