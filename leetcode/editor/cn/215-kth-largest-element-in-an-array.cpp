#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:

        int quickSelect(vector<int> &nums, int l, int r, int index)
        {
            int q = randomPartition(nums, l , r);

            if(q == index)
            { return nums[q]; }
            else
            {
                return q < index ? quickSelect(nums, q + 1, r, index) : quickSelect(nums, l, q - 1, index);
            }
        }

        int randomPartition(vector<int> &nums, int l, int r)
        {
            int i = (rand() % (r - l + 1)) + l;
            swap(nums[i], nums[l]);

            return partition(nums, l, r);
        }

        int partition(vector<int>& nums, int left, int right)
        {
            int pivot = nums[left];

            while(left < right)
            {
                while(left < right && nums[right] >= pivot ) --right;
                nums[left] = nums[right];

                while(left < right && nums[left] <= pivot) ++left;
                nums[right] = nums[left];
            }

            nums[left] = pivot;
            return left;
        }

        int findKthLargest(vector<int>& nums, int k)
        {
            srand(time(0));
            return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

