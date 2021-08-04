#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:

        int minDepth(TreeNode *root)
        {
            if (root == nullptr)
            { return 0; }

            if (root->left == nullptr && root->right != nullptr)
            { return minDepth(root->right) + 1; }

            if (root->right == nullptr && root->left != nullptr)
            { return minDepth(root->left) + 1; }

            return std::min(minDepth(root->left), minDepth(root->right)) + 1;
        }
};

//leetcode submit region end(Prohibit modification and deletion)

