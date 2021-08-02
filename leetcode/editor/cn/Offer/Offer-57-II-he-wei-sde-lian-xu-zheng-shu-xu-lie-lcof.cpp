//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。 
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
// 👍 254 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<vector<int>> findContinuousSequence(int target)
        {
            int left = 1;
            int right = 2;
            int sum = 3;
            vector<vector<int>> result;

            while(left < right)
            {
                if (sum == target)
                {
                    vector<int> ans(right - left + 1);
                    for (int k = left; k <= right; ++k) ans[k - left] = k;
                    result.push_back(ans);
                }
                if (sum < target)
                {
                    ++right;
                    sum += right;
                }
                else  // sum >= target
                {
                    sum -= left;
                    ++left;
                }
            }

            return result;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}