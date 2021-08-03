#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            std::vector<std::vector<int>> dp(
                    word1.length() + 1, vector<int>(word2.length() + 1, 0));

            // dp[i-1][j] + 1       delete
            // dp[i-1][j-1] + 1     change
            // dp[i][j-1] + 1       add

            for (int i = 0; i < dp.size(); i++) dp[i][0] = i;
            for (int j = 0; j < dp[0].size(); j++) dp[0][j] = j;

            for (int i = 1; i < dp.size(); i++)
            {
                for (int j = 1; j < dp[i].size(); j++)
                {
                    dp[i][j] = std::min(
                            dp[i - 1][j],
                            std::min(dp[i - 1][j - 1], d[i][j - 1])) + 1;

                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]);
                }
            }

            return dp.back().back();
        }
};
//leetcode submit region end(Prohibit modification and deletion)

