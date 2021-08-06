#include <iostream>
#include <vector>
#include "../include/TreeNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<int> postorderTraversal(TreeNode *root)
        {
            std::vector<int> ans;
            traverse(root, ans);

            return ans;
        }

        void traverse(TreeNode *cur, std::vector<int> &ans)
        {
            if (cur == nullptr) return;

            traverse(cur->left, ans);
            traverse(cur->right, ans);
            ans.emplace_back(cur->val);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

