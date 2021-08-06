//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法 
// 👍 218 👎 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> getLeastNumbersInSort(vector<int> &arr, int k)
        {
            // O(nlogn) O(logn)
            std::sort(arr.begin(), arr.end());

            return vector<int>(arr.begin(), arr.begin() + k);
        }

        vector<int> getLeastNumbers(vector<int> &arr, int k)
        {
            // O(nlogn) O(logn)
            quickSort(arr, 0, arr.size() - 1, k);

            for(auto it : arr)
            {
                cout << it << endl;
            }
            return vector<int>(arr.begin(), arr.begin() + k);
        }

        void quickSort(vector<int> &arr, int start, int end, int k)
        {
            if (start < end)
            {
                int pivotPos = partition(arr, start, end);

                if (pivotPos == k)
                { return; }

                //如果index < k，说明k在[index + 1, end]区间，递归找一次即可
                //如果index > k，说明k在[start, index - 1]区间，递归找一次即可
                if (pivotPos < k)
                {
                    quickSort(arr, pivotPos + 1, end, k);}
                else
                {
                    quickSort(arr, start, pivotPos - 1, k);
                }

            }
        }

        int partition(vector<int> &arr, int low, int high)
        {
            int temp = arr[low];

            while(low < high)
            {
                while(low < high && arr[high] >= temp) --high;
                arr[low] = arr[high];

                while(low < high && arr[low] <= temp) ++low;
                arr[high] = arr[low];
            }


            arr[low] = temp;
            return low;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    s.getLeastNumbers(data, 2);
}