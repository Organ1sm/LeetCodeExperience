//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 
//
// 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出: 2 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// 
// Related Topics 位运算 分治算法 
// 👍 132 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int majorityElement_hash(vector<int> &nums)
        {
            double range = nums.size() / 2;
            int ans;
            unordered_map<int, int> Hash;

            for (int i = 0; i < nums.size(); ++i)
            {
                Hash[nums[i]]++;
                if (Hash[nums[i]] > range)
                {
                    ans = nums[i];
                    break;
                }
            }

            return ans;
        }

        int majorityElement_sort(vector<int> &nums)
        {
            int range = nums.size() / 2;

            sort(nums.begin(), nums.end());

            return nums[range];
        }

        int majorityElement(vector<int> &nums)
        {
            // 我们只需找到票数抵消后最大的元素
            // 默认首元素已获得一票
            int ans = nums[0];
            int count = 1;

            for (int i = 1; i < nums.size(); ++i)
            {
                if (nums[i] != ans)
                { --count; }        // 投票并相互抵消
                else
                { ++count; }

                if (count == 0)
                {
                    ans = nums[i]; //获得选举人
                    count = 1;
                }
            }

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << s.majorityElement(data) << endl;

}