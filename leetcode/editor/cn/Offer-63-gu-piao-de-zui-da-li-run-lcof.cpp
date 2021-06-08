//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？ 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
// 
//
// 示例 2: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 10^5 
//
// 
//
// 注意：本题与主站 121 题相同：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-s
//tock/ 
// Related Topics 动态规划 
// 👍 117 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maxProfit1(vector<int> &prices)
        {
            // data [7,1,5,3,6,4]
            // dp[i]=max(dp[i−1],prices[i]−min(prices[0:i]))

            int minprice = prices[0];

            int dp[prices.size()];
            dp[0] = 0;

            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] < minprice)
                { minprice = prices[i]; }

                dp[i] = std::max(dp[i - 1], prices[i] - minprice);
            }

            return dp[prices.size() - 1];
        }

        int maxProfit(vector<int> &prices)
        {
            int minPrice = prices[0];
            int profit = 0;

            for(int i = 1; i < prices.size(); i++)
            {
                if(minPrice > prices[i]) minPrice = prices[i];

                profit = std::max(prices[i] - minPrice, profit);
            }

            return profit;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << s.maxProfit(data) << endl;

}