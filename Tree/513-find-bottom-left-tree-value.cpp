#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int maxDepth = INT_MIN;
        int ans;
        int findBottomLeftValue(TreeNode* root)
        {
            traverse(root, 0);
            return ans;
        }

        void traverse(TreeNode *node, int depth)
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                if(maxDepth < depth)
                {
                    maxDepth = depth;
                    ans = node->val;
                }
            }

            if(node->left) traverse(node->left, depth + 1);
            if(node->right) traverse(node->right, depth + 1);

        }
};

class Solution
{
    public:
        int findBottomLeftValue(TreeNode* root)
        {
            queue<TreeNode*> q;
            q.push(root);
            int ans = 0;
            while(!q.empty())
            {
                auto size = q.size();
                ans = q.front()->val;

                for(int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front(); q.pop();

                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

