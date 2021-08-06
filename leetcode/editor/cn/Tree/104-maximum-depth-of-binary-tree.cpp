#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maxDepth(TreeNode *root)
        {
            return getDepth(root);
        }

        int getDepth(TreeNode *node)
        {
            if (node == nullptr)
            { return 0; }

            int leftDepth = getDepth(node->left);
            int rightDepth = getDepth(node->right);

            return std::max(leftDepth, rightDepth) + 1;
        }
};

class Solution
{
    public:
        int maxDepth(TreeNode *root)
        {
            if (root == nullptr)
            { return 0; }
            queue < TreeNode * > q;
            int depth = 0;
            q.push(root);

            while(!q.empty())
            {
                auto size = q.size();
                ++depth;

                for (int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front();
                    q.pop();

                    if (cur->left)
                    { q.push(cur->left); }
                    if (cur->right)
                    { q.push(cur->right); }
                }
            }

            return depth;
        }
};

//leetcode submit region end(Prohibit modification and deletion)

