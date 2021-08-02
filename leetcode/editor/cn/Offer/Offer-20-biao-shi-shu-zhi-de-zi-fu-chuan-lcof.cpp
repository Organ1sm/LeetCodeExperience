//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"012
//3"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。 
//
// 
// Related Topics 数学 
// 👍 165 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{

    public:

        enum class State
        {
                // +100 +100.0
                // -100 -100.0
                // 5e2
                // 3.141516
                // 3 2
                // -1E-16

                InitSpace,          // 0
                IntSign,               // 1
                Integer,            // 2
                Point,              // 3
                PointWithoutInt,    // 4
                Fraction,           // 5
                Exp,                // 6
                ExpSign,            // 7
                ExpInteger,         // 8
                EndSpace            // 9
        };

        enum class CharType
        {
                Digit, Exp, Dot, Sign, Space, Illegal
        };
        unordered_map<State, unordered_map<CharType, State>> transfer;

        Solution()
        {
            this->transfer = {{State::InitSpace,       {{CharType::Space, State::InitSpace},  {CharType::Sign,  State::IntSign}, {CharType::Dot,   State::PointWithoutInt}, {CharType::Digit, State::Integer}}},
                              {State::IntSign,         {{CharType::Digit, State::Integer},    {CharType::Dot,   State::PointWithoutInt}}},
                              {State::Integer,         {{CharType::Digit, State::Integer},    {CharType::Exp,   State::Exp},     {CharType::Space, State::EndSpace},        {CharType::Dot,   State::Point}}},
                              {State::Point,           {{CharType::Digit, State::Fraction},   {CharType::Exp,   State::Exp},     {CharType::Space, State::EndSpace}}},
                              {State::PointWithoutInt, {{CharType::Digit, State::Fraction}}},
                              {State::Fraction,        {{CharType::Digit, State::Fraction},   {CharType::Exp,   State::Exp},     {CharType::Space, State::EndSpace}}},
                              {State::Exp,             {{CharType::Sign,  State::ExpSign},    {CharType::Digit, State::ExpInteger}}},
                              {State::ExpSign,         {{CharType::Digit, State::ExpInteger}}},
                              {State::ExpInteger,      {{CharType::Digit, State::ExpInteger}, {CharType::Space, State::EndSpace}}},
                              {State::EndSpace,        {{CharType::Space, State::EndSpace}}}};
        }

        bool isNumber(string s)
        {
            // 自动机开始状态
            State st = State::InitSpace;
            for (char ch : s)
            {
                CharType type = ConvertToRule(ch);
                if (transfer[st].find(type) == transfer[st].end())
                { return false; }
                else
                {
                    st = transfer[st][type];        // 转移后的新状态
                }
            }

            return st == State::Integer || st == State::Point || st == State::Fraction || st == State::ExpInteger ||
                   st == State::EndSpace;
        }

        CharType ConvertToRule(char ch)
        {
            if (ch >= '0' && ch <= '9')
            { return CharType::Digit; }
            else if (ch == 'e' || ch == 'E')
            { return CharType::Exp; }
            else if (ch == '.')
            { return CharType::Dot; }
            else if (ch == '+' || ch == '-')
            { return CharType::Sign; }
            else if (ch == ' ')
            { return CharType::Space; }
            else
            { return CharType::Illegal; }
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}