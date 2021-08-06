#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool isBalanced(TreeNode *root)
        {
            return maxDepth(root) != -1;
        }

        int maxDepth(TreeNode *node)
        {
            if(node == nullptr) return 0;

            int left = maxDepth(node->left);
            if(left == -1) return -1;

            int right = maxDepth(node->right);
            if(right == -1) return -1;

            return abs(left - right) > 1 ? -1 : 1 + std::max(left, right);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

