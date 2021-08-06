#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maximalSquare(vector<vector<char>> &matrix)
        {
            if (matrix.size() == 0 || matrix[0].size() == 0)
            { return 0; }

            int row = matrix.size();
            int col = matrix[0].size();
            int maxSide = 0;

            vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == '1')
                    {
                        dp[i + 1][j + 1] = std::min(
                                std::min(dp[i][j], dp[i + 1][j]),
                                dp[i][j + 1]
                        ) + 1;

                        maxSide = std::max(maxSide, dp[i + 1][j+1]);
                    }
                }
            }

            return maxSide * maxSide;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

