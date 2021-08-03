#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int longestCommonSubsequence(string text1, string text2)
        {
            int m = text1.length();
            int n = text2.length();

            // dp[i][j] 表示text1[0:i] 和 text2[0:j]的最长公共子序列的长度
            std::vector<std::vector<int>> dp(
                    m + 1, std::vector(n, 0));

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (text1[i - 1] == text2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }

            return dp[m][n];
        }
};
//leetcode submit region end(Prohibit modification and deletion)

