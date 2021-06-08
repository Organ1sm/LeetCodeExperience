#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        string findLongestWord(string s, vector<string> &dictionary)
        {
            string temp = "";
            for (const auto &matchStr :  dictionary)
            {
                if (!SubStr(s, matchStr))
                {
                    continue;
                }

                if ((matchStr.length() > temp.length()) ||
                    (matchStr.length() == temp.length() && matchStr.compare(temp) < 0))
                {
                    temp = matchStr;
                }
            }
            return temp;
        }

        bool SubStr(const string &s, const string &matchStr)
        {
            int t = 0;      // -> s
            int p = 0;      // -> matchStr

            while(t < s.length() && p < matchStr.length())
            {
                // 如果相等则两个指针都移动，否p则只移动原序列
                if (s[t] == matchStr[p])
                { ++p; }
                ++t;
            }

            return p == matchStr.length();
        }

};

//class SolutionDp {
//
//    public boolean isSubsequence(String t, String s) {
//            int n = s.length();
//            int[][] dp = new int[n + 1][26];
//            // 初始化结尾
//            for (int i = 0; i < 26; i++) {
//                dp[n][i] = n;
//            }
//            // 初始化 dp 数组
//            for (int i = n - 1; i >= 0; i--) {
//                for (int j = 0; j < 26; j++) {
//                    if (s.charAt(i) - 'a' == j) {
//                        dp[i][j] = i;
//                    } else {
//                        // 不相等，则继承上一位的值
//                        dp[i][j] = dp[i + 1][j];
//                    }
//                }
//            }
//            int index = 0;
//            for (char c : t.toCharArray()) {
//                // 如果下一个字符在结尾，则表示 s 中没有该字符
//                if (dp[index][c - 'a'] == n) {
//                    return false;
//                }
//                // 移动到下一个字符的后面
//                index = dp[index][c - 'a'] + 1;
//            }
//            return true;
//        }
//}

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}