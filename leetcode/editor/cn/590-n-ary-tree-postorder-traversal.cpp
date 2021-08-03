#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        vector<int> postorder(Node *root)
        {
            std::vector<int> ans;

            dfs(root, ans);
            return ans;
        }

        void dfs(Node *cur, vector<int> &ans)
        {
            if (cur == nullptr)
            { return; }

            for (auto &e : cur->children)
            {
                dfs(e, ans);
            }
            ans.emplace_back(cur->val);
        }
};

class Solution1
{
    public:
        vector<int> postorder(Node *root)
        {
            stack < Node * > s;
            vector<int> ans;
            Node *cur = nullptr;
            if (root != nullptr)
            { s.push(root); }

            while(!s.empty())
            {
                cur = s.top();
                s.pop();
                ans.emplace_back(cur->val);
                for (auto &e : cur->children)
                {
                    s.push(e);
                }
            }

            std::reverse(ans.begin(), ans.end());

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

