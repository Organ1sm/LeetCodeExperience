//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可
//能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。 
//
// 
//
// 示例 1: 
//
// 输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi" 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 231 
// 
// 👍 214 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int translateNum(int num)
        {
            string s = to_string(num);
            int a = 1;
            int b = 1;

            for (int i = 2; i <= s.length(); i++)
            {
                auto temp = s.substr(i - 2, 2);
                int c = temp.compare("10") >= 0 && temp.compare("25") <= 0 ? a + b : a;
                b = a;
                a = c;
            }

            return a;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    std::cout << s.translateNum(1250156147) << std::endl;

    cout << "Hello LeetCode" << endl;
}