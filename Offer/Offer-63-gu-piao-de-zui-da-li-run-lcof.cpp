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