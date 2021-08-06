#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        bool isSymmetric(TreeNode *root)
        {
            if (root == nullptr)
            { return true; }

            return compare(root->left, root->right);
        }

        bool compare(TreeNode *T1, TreeNode *T2)
        {
            if (T1 == nullptr && T2 == nullptr)
            { return true; }
            if (T1 == nullptr || T2 == nullptr)
            { return false; }

            return (T1->val == T2->val) && compare(T1->left, T2->right) &&
                   compare(T1->right, T2->left);

        }
};

class Solution2
{
    public:
        bool isSymmetric(TreeNode *root)
        {
            if (root == nullptr)
            { return true; }
            queue < TreeNode * > q;

            q.push(root->left);
            q.push(root->right);

            while(!q.empty())
            {
                TreeNode *T1 = q.front();
                q.pop();
                TreeNode *T2 = q.front();
                q.pop();

                if (T1 == nullptr && T2 == nullptr)
                { continue; }
                if (T1 == nullptr || T2 == nullptr)
                { return false; }

                if (T1->val != T2->val)
                { return false; }

                q.push(T1->left);
                q.push(T2->right);
                q.push(T1->right);
                q.push(T2->left);
            }

            return true;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

