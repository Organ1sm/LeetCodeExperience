#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int climbStairs0(int n)
        {
            // O(n) / O(n)
            if(n <= 1) return n;
            vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;

            for (int i = 3; i <= n; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }

            return dp[n];
        }
        int climbStairs(int n)
        {
            if(n <= 1) return n;

            int dp1 = 1;
            int dp2 = 2;
            int sum;

            for(int i = 3; i <= n; ++i)
            {
                sum = dp1 + dp2;
                dp1 = dp2;
                dp2 = sum;
            }
            return sum;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

