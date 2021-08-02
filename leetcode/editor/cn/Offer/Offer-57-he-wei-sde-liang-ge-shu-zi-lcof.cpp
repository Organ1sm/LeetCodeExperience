//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
// 
//
// 示例 2： 
//
// 输入：nums = [10,26,30,31,47,60], target = 40
//输出：[10,30] 或者 [30,10]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10^5 
// 1 <= nums[i] <= 10^6 
// 
// 👍 96 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
//        vector<int> twoSumInHash(vector<int>& nums, int target)
//        {
//            std::unordered_set<int>Hash;
//
//            for(int i = 0; i < nums.size(); i++)
//            {
//                int findele = target - nums[i];
//
//                if(Hash.find(findele) != Hash.end())
//                {
//                    return vector<int>{findele, nums[i]};
//                }
//
//                Hash.insert(nums[i]);
//            }
//
//            return vector<int>{};
//        }
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;

            while(left < right)
            {
                if (nums[left] + nums[right] == target)
                { return vector<int>{nums[left], nums[right]}; }

                else if (nums[left] + nums[right] > target)
                { --right; }
                else
                { --left; }
            }


            return vector<int>{};
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}