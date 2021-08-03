#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int trap1(vector<int> &height)
        {
            int sum = 0;

            for (int i = 1; i < height.size() - 1; ++i)
            {
                int maxLeft = 0;
                for (int j = i - 1; j >= 0; --j)
                {
                    maxLeft = std::max(maxLeft, height[j]);
                }

                int maxRight = 0;
                for (int k = i + 1; k < height.size(); ++k)
                {
                    maxRight = std::max(maxRight, height[k]);
                }

                int minHeight = std::min(maxLeft, maxRight);

                if (minHeight > height[i])
                { sum = sum + (minHeight - height[i]); }
            }
            return sum;
        }

        int trap2(vector<int> &height)
        {
            if (height.empty())
            { return 0; }
            int sum = 0;

            vector<int> maxLeft(height.size(), 0);
            vector<int> maxRight(height.size(), 0);

            for (int i = 1; i < height.size() - 1; ++i)
            {
                maxLeft[i] = std::max(maxLeft[i - 1], height[i - 1]);
            }

            for (int j = height.size() - 2; j >= 0; ++j)
            {
                maxRight[j] = std::max(maxRight[j + 1], height[j + 1]);
            }

            for (int i = 1; i < height.size() - 1; ++i)
            {
                int minHeight = std::min(maxLeft[i], maxRight[i]);
                if (minHeight > height[i])
                {
                    sum = sum + (minHeight - height[i]);
                }
            }

            return sum;
        }

        int trap(vector<int> &height)
        {
            if(height.size() < 3) return 0;

            int sum = 0;
            int maxLeft = 0;
            int maxRight = 0;
            int left = 1;
            int right = height.size() - 2;

            for (int i = 0; i < height.size() - 1; ++i)
            {
                if (height[left - 1] < height[right + 1])
                {
                    maxLeft = std::max(maxLeft, height[left - 1]);
                    int minHeight = maxLeft;
                    if(minHeight > height[left])
                    { sum = sum + (minHeight - height[left]); }
                    ++left;
                }
                else
                {
                    maxRight = std::max(maxRight, height[right + 1]);
                    int minHeight = maxRight;
                    if(minHeight > height[right])
                    { sum = sum + (minHeight - height[right]); }
                    --right;
                }
            }

            return sum;
        }

};
//leetcode submit region end(Prohibit modification and deletion)
