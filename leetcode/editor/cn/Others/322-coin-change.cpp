#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int coinChange(vector<int> &coins, int amount)
        {
            std::vector<int> dp(amount + 1, INT_MAX);
            dp[0] = 0;

            for (int i = 0; i < coins.size(); i++)
            {
                for (int j = coins[i]; j <= amount; j++)
                {
                    if (dp[j - coins[i]] != INT_MAX)
                    { dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]); }
                }
            }
            if (dp[amount] == INT_MAX)
            { return -1; }

            return dp[amount];
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{

    std::vector<int> coins{1, 2, 5};
    Solution s;
    s.coinChange(coins, 11);
    return 0;

}