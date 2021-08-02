//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
// Related Topics 数组 
// 👍 213 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        // 1. 先遍历至第一行末尾
        // 2. 加列至右下角元素
        //
        vector<int> spiralOrder(vector<vector<int>> &matrix)
        {
            if (matrix.size() == 0)
            { return {}; }

            vector<int> ans;
            ans.resize(matrix.size() * matrix[0].size());
            int up = 0;
            int bottom = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
            int index = 0;
            while(true)
            {
                // left -> right
                for (int i = left; i <= right; ++i)
                {
                    ans[index++] = matrix[up][i];
                }
                // 上边界往下移一行
                if (++up > bottom)
                { break; }

                // up -> bottom
                for (int i = up; i <= bottom; ++i)
                {
                    ans[index++] = matrix[i][right];
                }
                if (--right < left)
                { break; }

                // right -> left
                for (int i = right; i >= left; --i)
                {
                    ans[index++] = matrix[bottom][i];
                }
                if (--bottom < up)
                { break; }

                // bottom -> up
                for (int i = bottom; i >= up; --i)
                {
                    ans[index++] = matrix[i][left];
                }
                if (++left > right)
                { break; }
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<vector<int>> data{{1, 2,  3,  4},
                             {5, 6,  7,  8},
                             {9, 10, 11, 12}};

    s.spiralOrder(data);
    return 0;
};

