#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        TreeNode *invertTree(TreeNode *root)
        {
            if (root == nullptr)
            { return nullptr; }

            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);

            return root;
        }

};

class Solution
{
    public:
        TreeNode *invertTree(TreeNode *root)
        {
            stack < TreeNode * > s;
            if (root != nullptr)
            { s.push(root); }

            while(!s.empty())
            {
                TreeNode *cur = s.top();
                s.pop();

                std::swap(cur->left, cur->right);
                if (cur->left)
                { s.push(cur->left); }
                if (cur->right)
                { s.push(cur->right); }
            }

            return root;
        }

};
//leetcode submit region end(Prohibit modification and deletion)

