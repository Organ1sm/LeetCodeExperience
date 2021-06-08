//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// 👍 400 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int ans;

        int reversePairs1(vector<int> &nums)
        {
            // O(N^2)
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] > nums[j])
                    {
                        cnt++;
                    }
                }
            }

            return cnt;
        }

        void merge(vector<int> &nums, int left, int right)
        {
            int mid = (left + right) / 2;
            if (left < right)
            {
                merge(nums, left, mid);
                merge(nums, mid + 1, right);
                mergeSort(nums, left, mid, right);
            }
        }

        void mergeSort(vector<int> &nums, int left, int mid, int right)
        {
            vector<int> temp(right - left + 1);
            int cur = 0;
            int i = left;
            int j = mid + 1;

            while(i <= mid && j <= right)
            {
                if (nums[i] <= nums[j])
                {
                    temp[cur++] = nums[i++];
                }
                else
                {
                    this->ans += (mid - i + 1);
                    temp[cur++] = nums[j++];
                }
            }

            while(i <= mid) temp[cur++] = nums[i++];
            while(j <= right) temp[cur++] = nums[j++];

            //把新数组中的数覆盖nums数组
            for (int k = 0; k < temp.size(); k++)
            {
                nums[left + k] = temp[k];
            }
        }

        int reversePairs(vector<int> &nums)
        {
            this->ans = 0;
            merge(nums, 0, nums.size() - 1);
            return this->ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 5, 6, 4};
    cout << s.reversePairs(data) << endl;

    cout << "Hello LeetCode" << endl;
}