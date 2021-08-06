#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            long long numbertor = 1;    // 分子
            int denominator = m - 1;    // 分母
            int count = m - 1;
            int t = m + n - 2;

            while(count--)
            {
                numbertor *= (t--);
                while(denominator != 0 && numbertor % denominator == 0)
                {
                    numbertor /= denominator;
                    denominator--;
                }
            }
            return numbertor;
        }

        int uniquePaths1(int m, int n)
        {
            // dp[i][j] 表示从(0, 0) 到 (i, j)的路径数
            // 每次只能向下或者向右走 所以
            // dp[i][j] = dp[i-1][j] + dp[i][j-1]

            std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

            for (int i = 0; i < m; i++) dp[i][0] = 1;
            for (int j = 0; j < n; j++) dp[0][j] = 1;


            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }

            return dp.back().back();
        }
};
//leetcode submit region end(Prohibit modification and deletion)

