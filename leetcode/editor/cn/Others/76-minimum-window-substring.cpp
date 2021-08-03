#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        string minWindow(string s, string t)
        {
            vector<int> need(128, 0);
            int match = t.length();

            for (auto &c : t) need[c]++;

            int left = 0;
            int right = 0;
            int start = 0;                  // 子串起始位置
            int size = INT_MAX;             // 最小字串长度

            while(right < s.length())
            {
                char c = s[right];
                if (need[c] > 0)
                { --match; }

                need[c]--; //先把右边的字符加入窗口

                if (match == 0)
                {
                    while(left < right && need[s[left]] < 0)
                    {
                        need[s[left]]++;
                        ++left;
                    }

                    int len = right - left + 1;
                    if (len < size)
                    {
                        size = len;
                        start = left;
                    }
                    need[s[left]]++;
                    ++left;
                    ++match;
                }
                ++right;
            }

            return size == INT_MAX ? "" : s.substr(start, size);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    s.minWindow("ADOBECODEBANC", "ABC");
    return 0;

}