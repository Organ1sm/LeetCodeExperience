//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。 
//
// 示例 1: 
//
// 输入: n = 1
//输出: [1,2,3,4,5,6,7,8,9]
// 
//
// 
//
// 说明： 
//
// 
// 用返回一个整数列表来代替打印 
// n 为正整数 
// 
// Related Topics 数学 
// 👍 99 👎 0

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> printNumbers(int n)
        {
            // O(10^n)
            // O(1)
            int range = pow(10, n);
            vector<int> ans;
            ans.resize(range-1);

            for (int i = 1; i <= range - 1; ++i)
                ans[i - 1] = i;

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    auto v = s.printNumbers(3);
    for (auto it : v)
    {
        cout << it << endl;
    }
}