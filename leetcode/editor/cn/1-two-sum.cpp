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
                }
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
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}