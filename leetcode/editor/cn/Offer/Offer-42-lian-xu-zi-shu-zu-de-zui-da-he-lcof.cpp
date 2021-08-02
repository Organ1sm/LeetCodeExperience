//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。 
//
// 要求时间复杂度为O(n)。 
//
// 
//
// 示例1: 
//
// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^5 
// -100 <= arr[i] <= 100 
// 
//
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ 
//
// 
// Related Topics 分治算法 动态规划 
// 👍 258 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maxSubArray1(vector<int> &nums)
        {
            // 暴力匹配
            int max = INT_MIN;
            for (decltype(nums.size()) i = 0; i < nums.size(); i++)
            {
                int sum = 0;
                for (decltype(nums.size()) j = i + 1; j < nums.size(); j++)
                {
                    sum += nums[j];
                    if (sum > max)
                    {
                        max = sum;
                    }
                }
            }
            return max;
        }

        int maxSubArray(vector<int> &nums)
        {
//            int dp[nums.size()];
//            int ans = nums[0];
//
//            dp[0] = nums[0];
//
//            for (int i = 1; i < nums.size(); i++)
//            {
//                dp[i] = std::max(0, dp[i - 1]) + nums[i];
//                ans = std::max(ans, dp[i]);
//            }
//            return ans;

//          // 优化后
            int ans = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                nums[i] = std::max(0, nums[i - 1]) + nums[i];
                ans = std::max(ans, nums[i]);
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{-2, 1, -3, 4, -1, 2, 1, -5, 4};


    cout << s.maxSubArray(data) << endl;
}