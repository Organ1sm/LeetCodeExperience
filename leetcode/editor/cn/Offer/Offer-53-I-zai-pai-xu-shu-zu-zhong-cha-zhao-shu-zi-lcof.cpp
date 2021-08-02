//统计一个数字在排序数组中出现的次数。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
// Related Topics 数组 二分查找 
// 👍 123 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int searchInHash(vector<int> &nums, int target)
        {
            std::unordered_map<int, int> Hash;

            for (size_t i = 0; i < nums.size(); i++)
            {
                if (Hash.find(nums[i]) != Hash.end())
                {
                    Hash[nums[i]]++;
                }
                else
                {
                    Hash[nums[i]] = 1;
                }
            }

            return Hash[target];
        }

//        int search(vector<int> &nums, int target)
//        {
//            return helper(nums, target) - helper(nums, target - 1);
//        }
//
//        int helper(vector<int> &nums, int target)
//        {
//            int i = 0;
//            int j = nums.size() - 1;
//
//            while(i <= j)
//            {
//                int mid = (i + j) / 2;
//                if (nums[mid] <= target)
//                { i = mid + 1; }
//                else
//                { j = mid - 1; }
//            }
//
//            return i;
//        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{5, 6, 6, 8, 8, 10};
    cout << s.search(data, 8) << endl;
    cout << "Hello LeetCode" << endl;
}