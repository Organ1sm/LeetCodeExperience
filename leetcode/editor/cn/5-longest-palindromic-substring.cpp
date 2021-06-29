#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        string longestPalindrome0(string s)
        {
            string ans;
            int len = s.length();

            int maxLen = 0;
            for (int i = 0; i < len; ++i)
            {
                for (int j = i + 1; j <= len; ++j)
                {
                    string sstr = s.substr(i, j - i);
                    if (isPalindrome(sstr) && sstr.length() > maxLen)
                    {
                        ans = s.substr(i, j - i);
                        int length = sstr.length();
                        maxLen = std::max(maxLen, length);
                    }
                }
            }

            return ans;

        }

        bool isPalindrome(const string &s)
        {
            int len = s.length();
            for (int i = 0; i < len / 2; ++i)
            {
                if (s[i] != s[len - i - 1])
                { return false; }
            }
            return true;
        }

        string longestPalindrome1(string s)
        {
            int maxLength = 0;
            int left = 0;
            int right = 0;
            vector<vector<int>> dp(s.length(), vector<int>(s.size(), 0));


            for (int i = s.length() - 1; i >= 0; --i)
            {
                for (int j = i; j < s.length(); ++j)
                {
                    if (s[i] == s[j])
                    {
                        if (j - i <= 1 || dp[i + 1][j - 1])
                        { dp[i][j] = 1; }  // ”a“, "aa"

                    }
                    if (dp[i][j] && j - i + 1 > maxLength)
                    {
                        maxLength = j - i + 1;
                        left = i;
                    }
                }
            }

            return s.substr(left, maxLength);
        }

        string longestPalindrome(string s)
        {
            for (int i = 0; i < s.length(); i++)
            {
                extend(s, i, i);
                extend(s, i, i + 1);
            }

            return s.substr(this->left, this->maxLength);
        }

        void extend(const string &s, int i, int j)
        {
            int len =  s.length();
            while(i >= 0 && j < len && s[i] == s[j])
            {
                if (j - i + 1 > this->maxLength)
                {
                    this->left = i;
                    this->maxLength = j - i + 1;
                }

                --i;
                ++j;
            }
        }

    private:
        int maxLength = 0;
        int left = 0;
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;

    cout << s.longestPalindrome("babbd") << endl;
    return 0;
}