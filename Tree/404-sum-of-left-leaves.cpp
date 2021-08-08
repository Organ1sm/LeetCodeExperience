#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int sumOfLeftLeaves(TreeNode *root)
        {
            if (root == nullptr)
            { return 0; }

            int midValue = 0;
            if (root->left && !root->left->left && !root->left->right)
            {
                midValue = root->left->val;
            }

            int leftValue = sumOfLeftLeaves(root->left);
            int rightValue = sumOfLeftLeaves(root->right);

            return midValue + leftValue + rightValue;
        }
};

//leetcode submit region end(Prohibit modification and deletion)

