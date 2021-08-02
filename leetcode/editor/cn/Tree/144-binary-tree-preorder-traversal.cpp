#include <iostream>
#include <vector>
#include "../include/TreeNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        vector<int> preorderTraversal(TreeNode *root)
        {
            std::vector<int> res;
            travese(root, res);

            return res;
        }

        void travese(TreeNode *cur, vector<int> &res)
        {
            if (cur == nullptr)
            { return; }

            res.push_back(cur->val);
            travese(cur->left, res);
            travese(cur->right, res);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

