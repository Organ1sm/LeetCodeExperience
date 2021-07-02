#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            vector<int> minNums;

            for(int e : nums)
            {
                auto pos = std::lower_bound(minNums.begin(), minNums.end(), e);
                if (pos == minNums.end())
                { minNums.push_back(e); }
                else
                { *pos = e;}
            }

            return minNums.size();
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> v1{7, 7, 7, 7, 7, 7, 7};
    vector<int> v2{0, 1, 0, 3, 2, 3};
   s.lengthOfLIS(v1);
    s.lengthOfLIS(v2);
    return 0;
}