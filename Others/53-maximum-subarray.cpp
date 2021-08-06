#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maxSubArray0(vector<int> &nums)
        {
            int maxSum = INT_MIN;

            for (int i = 0; i < nums.size(); ++i)
            {
                int sum = 0;
                for (int j = i; j < nums.size(); ++j)
                {
                    sum += nums[j];
                    maxSum = std::max(sum, maxSum);
                }
            }
            return maxSum;
        }

        int maxSubArray(vector<int> &nums)
        {
            int ans = nums[0];
            int dp  = 0;

            for(const int &e : nums)
            {
                dp = std::max(e, dp + e);
                ans = std::max(ans, dp);
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

