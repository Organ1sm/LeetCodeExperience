#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            if (nums.empty()) return;

            int i = 0;
            int j = 0;

            for(; i < nums.size(); ++i)
            {
                if(nums[i] != 0)
                {
                    if(i > j)
                    {
                        nums[j] = nums[i];
                        nums[i] = 0;
                    }
                    j++;
                }
            }
        }
};
//leetcode submit region end(Prohibit modification and deletion)

