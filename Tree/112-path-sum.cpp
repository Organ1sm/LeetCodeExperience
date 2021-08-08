#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            if(root == nullptr) return false;
            return traverse(root, targetSum - root->val);
        }

        bool traverse(TreeNode* cur, int count)
        {
            if(!cur->left && !cur->right && count == 0) return true;
            if(!cur->left && !cur->right) return false;

            if(cur->left && traverse(cur->left, count - cur->left->val)) return true;
            if(cur->right && traverse(cur->right, count - cur->right->val)) return true;

            return false;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

