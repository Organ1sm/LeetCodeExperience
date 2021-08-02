//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 
//
// 
//
// 示例 1: 
//
// 输入: [10,2]
//输出: "102" 
//
// 示例 2: 
//
// 输入: [3,30,34,5,9]
//输出: "3033459" 
//
// 
//
// 提示: 
//
// 
// 0 < nums.length <= 100 
// 
//
// 说明: 
//
// 
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数 
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0 
// 
// Related Topics 排序 
// 👍 198 👎 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        string minNumber(vector<int> &nums)
        {
            vector<string> strs;
            strs.resize(nums.size());
            for (size_t i = 0; i < nums.size(); i++)
            {
                strs[i] = to_string(nums[i]);
            }

            std::sort(strs.begin(), strs.end(), [](string &x, string &y) { return x + y < y + x; });

            string res;
            for (int i = 0; i < strs.size(); ++i)
            {
                res.append(strs[i]);
            }
            return res;
        }

    private:
        void quickSort(vector<std::string> &strs, int left, int right)
        {
            if (left > right)
            { return; }

            int i = left;
            int j = right;
            while(i < j)
            {
                // 3, 30
                // '3' + '30' > '30' + '3'

                // 从右边找一个排在strs[left]前面的数
                while(strs[j] + strs[left] >= strs[left] + strs[j] && i < j) j--;

                // 从左边找一个排在str[left]后面的数
                while(strs[i] + strs[left] <= strs[left] + strs[i] && i > j) i++;

                std::swap(strs[i], strs[j]);
            }
            std::swap(strs[i], strs[left]);
            quickSort(strs, left, i - 1);
            quickSort(strs, j + 1, right);

        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}