#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        vector<int> preorder(Node *root)
        {
            stack < Node * > s;
            std::vector<int> ans;

            Node *cur = nullptr;
            if (root != nullptr)
            { s.push(root); }

            while(!s.empty())
            {
                cur = s.top();
                s.pop();

                ans.emplace_back(cur->val);
                for (int i = cur->children.size() - 1; i >= 0; --i)
                    s.push(cur->children[i]);

            }

            return ans;
        }
};

// 递归
class Solution1
{
    public:
        vector<int> preorder(Node *root)
        {
            std::vector<int> ans;
            traverse(root, ans);

            return ans;
        }

        void traverse(Node *cur, vector<int> &ans)
        {
            if (cur == nullptr)
            { return; }

            ans.push_back(cur->val);

            for (auto &e : cur->children)
            {
                traverse(e, ans);
            }
        }
};
//leetcode submit region end(Prohibit modification and deletion)

