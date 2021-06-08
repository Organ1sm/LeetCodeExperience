//找出数组中重复的数字。 
//
// 
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请
//找出数组中任意一个重复的数字。 
//
// 示例 1： 
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
// 
//
// 
//
// 限制： 
//
// 2 <= n <= 100000 
// Related Topics 数组 哈希表 
// 👍 324 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int findRepeatNumber(vector<int> &nums)
        {
            int size = nums.size();
            for (int i = 0; i < size; i++)
            {
                while(nums[i] != i)
                {
                    int temp = nums[i];        // 看你是哪个坑的萝卜

                    if(nums[temp] == temp)
                    {
                        // 已经有萝卜了
                        return temp;
                    }
                    else
                    {
                        swap(nums[i], nums[temp]);
                    }
                }
            }
            return -1;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4, 3};
    cout << s.findRepeatNumber(data);
}