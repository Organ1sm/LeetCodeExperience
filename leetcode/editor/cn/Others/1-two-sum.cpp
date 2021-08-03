#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            // <value, Index>
            vector<int> ans;
            unordered_map<int, int> hashMap;
            for (int i = 0; i < nums.size(); i++)
            {
                auto num = nums[i];
                auto it = hashMap.find(target - num);
                if (it == hashMap.cend())
                {
                    hashMap[num] = i;

                    else
                    {
                        ans.push_back(i);
                        ans.push_back(hashMap[target - num]);
                        break;
                    }
                }
                return ans;
            }
        };
}
//leetcode submit region end(Prohibit modification and deletion)