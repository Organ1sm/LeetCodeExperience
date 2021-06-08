//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 示例 4: 
//
// 
//输入: s = ""
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 104 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 5112 👎 0
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//class Solution_BruteForce
//{
//    public:
//        int lengthOfLongestSubstring(string s)
//        {
//            int n = s.size();
//            int ans = 1;
//
//            if (s.empty())
//            {
//                return 0;
//            }
//
//            for (int i = 0; i < n; i++)
//            {
//                for (int j = i + 1; j < n; j++)
//                {
//                    if (Unique(s, i, j))
//                    {
//                        int length = j - i + 1;
//                        ans = ans > length ? ans : length;
//                    }
//                }
//            }
//            return ans;
//        }
//
//        bool Unique(const string &str, int start, int end)
//        {
//            // str[start:end] 表示str的一个substr
//            unordered_set<char> HashSet;
//            for (int i = start; i <= end; i++)
//            {
//                if (HashSet.find(str[i]) == HashSet.end())
//                {
//                    HashSet.insert(str[i]);
//                }
//                else
//                { return false; }
//
//            }
//
//            return true;
//        }
//};

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int ans = 0;
            unordered_map<char, int> hashMap;
            int left = 0;
            int right = 0;
            int length = 0;

            while(right < s.length())
            {

                if (hashMap.find(s[right]) != hashMap.end() && hashMap[s[right]] >= left)
                {
                    // s[right]与s[left : right)中的字符有重复
                    left = hashMap[s[right]] + 1;
                    length = right - left;
                }
                hashMap[s[right]] = right;
                ++right;
                ++length;
                ans = ans > length ? ans : length;
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    string str = "abcabcbb";
    std::cout << s.lengthOfLongestSubstring(str) << endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    std::cout << s.lengthOfLongestSubstring("abba") << endl;
    std::cout << s.lengthOfLongestSubstring(" ") << endl;
    std::cout << s.lengthOfLongestSubstring("") << endl;

    return 0;
}