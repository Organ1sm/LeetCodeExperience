#include <iostream>
#include <vector>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
  public:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3) return 0;
        std::sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int left  = j + 1;
                int right = nums.size();
                int sum   = nums[i] + nums[j];

                while (left < right)
                {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum)
                        left = mid + 1;
                    else
                        right = mid;
                }
                count += (left - j - 1);
            }
        }

        return count;
    }
};    // leetcode submit region end(Prohibit modification and deletion)


int main()
{
    std::vector<int> nums = {2, 2, 3, 4};
    Solution s;
    s.triangleNumber(nums);
    return 0;
}