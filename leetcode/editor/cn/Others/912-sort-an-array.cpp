#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int partition(vector<int> &nums, int l, int r)
        {
            int pivot = nums[l];
            int i = l + 1, j = r;
            while(true)
            {
                while(i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
                while(i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
                if (i > j)
                { break; }
                swap(nums[i], nums[j]);
            }
            //把arr[j]和主元交换
            swap(nums[j], nums[l]);
            return j;//为什么返回j而不是i，因为swap是先执行i++的while语句，如果和下面的替换顺序，则返回i
        }

        int randomPartition(vector<int> &nums, int l, int r)
        {
            int i = (rand() % (r - l + 1)) + l;
            swap(nums[i], nums[l]);
            return partition(nums, l, r);
        }

        void quickSort(vector<int> &nums, int left, int right)
        {
            if (left >= right)
            { return; }

            int mid = randomPartition(nums, left, right);
            quickSort(nums, left, mid - 1);
            quickSort(nums, mid + 1, right);
        }

        vector<int> sortArray(vector<int> &nums)
        {
            quickSort(nums, 0, nums.size() - 1);
            return nums;
        }
};

int main()
{

    vector<int> v{3, 2, 3, 5, 1, 2, 4, 6, 5};
    Solution s;
    s.sortArray(v);
    for (auto i : v)
    {
        cout << i << ' ';
    }

    cout << endl;
    return 0;
}
//leetcode submit region end(Prohibit modification and deletion)

