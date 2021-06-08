//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 
//
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nu
//ms2 的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//输出：[1,2,2,3,5,6]
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m + n 
// nums2.length == n 
// 0 <= m, n <= 200 
// 1 <= m + n <= 200 
// -109 <= nums1[i], nums2[i] <= 109 
// 
// Related Topics 数组 双指针 
// 👍 800 👎 0

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