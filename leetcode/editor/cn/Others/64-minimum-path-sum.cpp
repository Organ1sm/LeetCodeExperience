#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int minPathSum(vector<vector<int>> &grid)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                for(int j = 0; j < grid[0].size(); j++)
                {
                    if (i == 0 && j == 0) continue;
                    else if (j == 0) grid[i][j] += grid[i-1][j];
                    else if (i == 0) grid[i][j] += grid[i][j-1];
                    else grid[i][j] += std::min(grid[i-1][j], grid[i][j-1])
                }
            }

            return grid.back().back();
        }
};
//leetcode submit region end(Prohibit modification and deletion)

