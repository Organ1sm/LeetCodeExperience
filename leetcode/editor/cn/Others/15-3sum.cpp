#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int> &nums)
        {
            if(nums.size() < 3) return {};

            vector<vector<int>> res;
            std::sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size(); ++i)
            {
                if(nums[i] > 0) return res;

                // 去重
                if(i > 0 && nums[i] == nums[i-1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;

                while(left < right)
                {
                    int sum = nums[left] + nums[right] + nums[i];
                    if(sum == 0)
                    {
                        res.push_back(vector<int>{nums[left], nums[right], nums[i]});
                        ++left;
                        --right;

                        // 去重复
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < 0) ++left;
                    else if (sum > 0) --right;
                }
            }

            return res;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

