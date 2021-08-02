//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// 👍 86 👎 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{

    public:
        string replaceSpace_low(string s)
        {
            string reStr = "%20";
            auto it = s.begin();

            while(it != s.end())
            {
                if (*it == ' ')
                {
                    // 删除空格
                    it = s.erase(it);
                    it = s.insert(it, reStr.begin(), reStr.end());
                    it += reStr.size();
                }
                else
                { ++it; }
            }

            return s;

        }

        string replaceSpace(string s)
        {
            // 统计空格个数
            auto spaceCount = std::count(s.cbegin(), s.cend(), ' ');
            int ordinarySize = s.size();

            s.resize(s.size() + 2 * spaceCount);

            int i = ordinarySize - 1;
            int j = s.size() - 1;

            for (; i < j; j--, i--)
            {
                // 如果遇到空格 i替换
                if (s[i] == ' ')
                {
                    s[j] = '0';
                    s[j - 1] = '2';
                    s[j - 2] = '%';
                    j -= 2;
                }
                else
                {
                    s[j] = s[i];
                }
            }
            return s;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    cout << s.replaceSpace("We are Happy ");
}