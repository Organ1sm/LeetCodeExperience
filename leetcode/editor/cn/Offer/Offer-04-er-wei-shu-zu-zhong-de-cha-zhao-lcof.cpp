//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个
//整数，判断数组中是否含有该整数。 
//
// 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// 
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
//
// 
//
// 限制： 
//
// 0 <= n <= 1000 
//
// 0 <= m <= 1000 
//
// 
//
// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 
// Related Topics 数组 双指针 
// 👍 268 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:

        // 1. 可以对每一行进行二分查找
        // 2. 利用
        bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
        {
            if (matrix.empty())
            { return false; }

            int rows = matrix.size();
            int columns = matrix[0].size();


            // 利用二位数组列行递增的特点
            // 从右上角出发
            int row = 0;
            int col = columns - 1;

            while(row < rows && col >= 0)
            {
                if (matrix[row][col] == target)
                {
                    return true;
                }
                else if (matrix[row][col] < target)
                {
                    ++row;
                    continue;
                }
                else
                {
                    // 消去一列
                    --col;
                    continue;
                }
            }

            return false;

        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}