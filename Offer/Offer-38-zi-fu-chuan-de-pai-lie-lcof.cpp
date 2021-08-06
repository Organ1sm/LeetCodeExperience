//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法 
// 👍 222 👎 0

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{

    public:
        vector<string> permutation(string s)
        {
            vector<bool> visited(s.size(), false);
            sort(s.begin(), s.end());
            string path = "";
            dfs(path, s, visited);

            return ans;
        }

    private:
        vector<string> ans;

        void dfs(string &path, string &s, vector<bool> &visited)
        {
            if (path.size() == s.size())
            {
                ans.push_back(path);
                return;
            }


            for (int i = 0; i < s.size(); ++i)
            {
                // 已经访问过，跳过
                if (visited[i])
                { continue; }

                if (i > 0 && s[i - 1] == s[i] && visited[i - 1])
                { continue; }

                visited[i] = true;
                path += s[i];

                dfs(path, s, visited);
                path.pop_back();

                visited[i] = false;
            }
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    auto res = s.permutation("abb");

    for (auto it : res)
    {
        cout << it << " ";
    }

}