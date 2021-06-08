//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
// 
//
// 示例： 
//
// 
//输入：nums = [1,2,3,4]
//输出：[1,3,2,4] 
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 50000 
// 1 <= nums[i] <= 10000 
// 
// 👍 100 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> exchange_1(vector<int> &nums)
        {
            //
            if (nums.size() == 0)
            { return {}; }

            int left = 0;
            int right = nums.size() - 1;

            while(left < right)
            {
                if (nums[left] % 2 == 0)
                {
                    while(left < right)
                    {
                        if (nums[right] % 2 != 0)
                        {
                            swap(nums[left], nums[right]);
                            --right;
                            break;
                        }
                        --right;
                    }
                }
                ++left;

            }

            return nums;
        }

        vector<int> exchange(vector<int> &nums)
        {
            if (nums.size() == 0)
            { return {}; }

            int left = 0;
            int right = nums.size() - 1;

            while(left < right)
            {
                if (nums[left] % 2 != 0)
                {
                    ++left;
                    continue;
                }

                if (nums[right] % 2 == 0)
                {
                    --right;
                    continue;
                }
                swap(nums[left++], nums[right--]);
            }

            return nums;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 8, 1, 5, 3, 6, 2, 13, 4};

    auto v = s.exchange(data);

    for (auto item : v)
    {
        cout << item << " ";
    }
}