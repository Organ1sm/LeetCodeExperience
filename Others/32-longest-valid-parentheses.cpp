#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            if (s.empty())
            { return 0; }

            int ans = 0;

            std::vector<int> dp(s.length(), 0);

            for (int i = 1; i < s.length(); i++)
            {
                if (s[i] == ')')
                {
                    if (s[i - 1] == '(')
                    {
                        dp[i] = (i - 2) >= 0 ? dp[i - 2] + 2 : 2;
                    }
                    else if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 &&
                             s[i - dp[i - 1] - 1] == '(')
                    {
                        int pre = (i - dp[i-1]-2 >= 0 ? dp[i - dp[i-1] -2] : 0);
                        dp[i] = dp[i - 1] + 2 + pre;
                    }
                }

                ans = std::max(ans, dp[i]);
            }


            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

