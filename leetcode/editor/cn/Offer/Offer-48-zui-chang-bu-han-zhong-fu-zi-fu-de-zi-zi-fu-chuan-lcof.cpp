//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。 
//
// 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// s.length <= 40000 
// 
//
// 注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-rep
//eating-characters/ 
// Related Topics 哈希表 双指针 Sliding Window 
// 👍 190 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int lengthOfLongestSubstring1(string s)
        {
            int ans = 0;
            int left = 0;
            int right = 0;
            int substrlen = 0;
            // 存放字符和其不重复字串的索引
            std::unordered_map<char, int> hashMap;

            while(right < s.length())
            {
                if (hashMap.find(s[right]) != hashMap.end() && hashMap[right] >= left)
                {
                    left = hashMap[s[right]] + 1;
                    substrlen = right - left;
                }
                hashMap[s[right]] = right;
                ++right;
                ++substrlen;
                ans = ans > substrlen ? ans : substrlen;
            }

            return ans;
        }

        int lengthOfLongestSubstring(string s)
        {
            std::unordered_map<char, int> hashMap;
            int ans = 0;
            int start = -1;

            for (int i = 0; i < s.size(); i++)
            {
                if (hashMap[s[i]] > start)
                { start = hashMap[s[i]]; }

                hashMap[s[i]] = i;
                ans = std::max(ans, i - start);
            }

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("au") << endl;

    cout << "Hello LeetCode" << endl;
}