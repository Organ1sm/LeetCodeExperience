//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
//则输出"student. a am I"。 
//
// 
//
// 示例 1： 
//
// 输入: "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 说明： 
//
// 
// 无空格字符构成一个单词。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
//
//
// 注意：此题对比原题有改动 
// Related Topics 字符串 
// 👍 90 👎 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        string reverseWords(string s)
        {
            string ans;
            std::vector<string> temp;

            ltrim(s);
            rtrim(s);

            int slow = s.length() - 1;
            int fast = slow;

            while(fast >= 0)
            {
                while(fast >= 0 && s[fast] != ' ') fast--;
                ans.append(s.substr(fast + 1, slow - fast) + " ");
                while(fast >= 0 && s[fast] == ' ') fast--;
                slow = fast;
            }
            rtrim(ans);

            return ans;
        }

        void rtrim(string &s)
        {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
            {
                return !std::isspace(ch);
            }).base(), s.end());
        }

        void ltrim(string &s)
        {
            // 去掉左边空格
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
            {
                return !std::isspace(ch);
            }));
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    cout << s.reverseWords("the sky is blue") << "*";

}