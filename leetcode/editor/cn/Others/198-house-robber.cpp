#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            if (nums.empty())
            { return 0; }

            // 子问题：
            // f(k) = 偷 [0..k) 房间中的最大金额

            // f(0) = 0
            // f(1) = nums[0]
            // f(k) = max{ rob(k-1), nums[k-1] + rob(k-2) }

            int n = nums.size();
            std::vector<int> dp(n + 1, 0);
            dp[0] = 0;
            dp[1] = nums[0];

            for (int i = 2; i <= n; i++)
                dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            return dp.back();
        }

};
//leetcode submit region end(Prohibit modification and deletion)

