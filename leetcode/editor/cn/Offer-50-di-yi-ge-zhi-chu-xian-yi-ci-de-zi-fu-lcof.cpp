//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例: 
//
// s = "abaccdeff"
//返回 "b"
//
//s = "" 
//返回 " "
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 哈希表 
// 👍 87 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        char firstUniqChar(string s)
        {
            vector<char> keys;
            std::unordered_map<char, bool> hashMap;

            for (char &i : s)
            {
                if (hashMap.find(i) == hashMap.end())
                {
                    keys.push_back(i);
                    hashMap[i] = true;
                }
                else
                {
                    hashMap[i] = false;
                }
            }
            for (char &c : keys)
            {
                if (hashMap[c])
                { return c; }
            }

            return ' ';
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}