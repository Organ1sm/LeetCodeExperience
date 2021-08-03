#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution_easy
{
        // 这里需要
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            if (n == 0)
            { return; }
            int first = 0;
            int second = 0;
            vector<int> temp;
            temp.reserve(m + n);

            while(first < m && second < n)
            {
                if (nums1[first] <= nums2[second])
                {
                    temp.push_back(nums1[first++]);
                }
                else
                {
                    temp.push_back(nums2[second++]);
                }

            }

            while(first < m)
            {
                temp.push_back(nums1[first++]);
            }

            while(second < n)
            {
                temp.push_back(nums2[second++]);
            }
            std::copy(temp.begin(), temp.end(), nums1.begin());
        }
};

class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            if (n == 0)
            { return; }

            int first = m - 1;
            int second = n - 1;
            int pos = m + n - 1;   // use for copy

            while(first >= 0 && second >= 0)
            {
                nums1[pos--] = (nums1[first] > nums2[second] ? nums1[first--] : nums2[second--]);
            }

            while(second >= 0)
            {
                nums1[pos--] = nums2[second--];
            }

        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data1{1, 2, 3, 0, 0, 0};
    vector<int> data2{2, 5, 6};
    s.merge(data1, 3, data2, 3);
}