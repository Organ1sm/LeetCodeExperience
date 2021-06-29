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
//            return true;
//        }
//};

class Solution
{
    public:
        int lengthOfLongestSubstring1(string s)
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

        int lengthOfLongestSubstring(string str)
        {
            int ans = 0;
            std::vector<int> m(128, 0);
            int left = 0;
            int right = 0;

            while(right < str.length())
            {
                // s[right]与s[left : right)中的字符有重复
                if (m[str[right]] != 0)
                { left = max(left, m[str[right]]); }

                // 更新字符索引,为什么记录的right + 1 而不是 right?
                // 因为出现重复字符时，调整window的左边界至重复字符的下一个位置
                // 所以可以解释一通
                m[str[right]] = right + 1;

                ans = max(ans, right - left + 1);
                ++right;
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    string str = "abcabcbb";
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << endl;        // 3
    std::cout << s.lengthOfLongestSubstring("pwwkew") << endl;          // 3
    std::cout << s.lengthOfLongestSubstring("abba") << endl;            // 2
    std::cout << s.lengthOfLongestSubstring(" ") << endl;               // 1
    std::cout << s.lengthOfLongestSubstring("") << endl;                // 0

    return 0;
}