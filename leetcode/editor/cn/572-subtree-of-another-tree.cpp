#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool isSubtree(TreeNode* root, TreeNode* subRoot)
        {
            if(subRoot == nullptr) return true;
            if(root == nullptr)    return false;
            return compare(root, subRoot) || isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        }

        bool compare(TreeNode *T1, TreeNode *T2)
        {
            if(T1 == nullptr && T2 == nullptr) return true;
            if(T1 == nullptr || T2 == nullptr) return false;
            if(T1->val != T2->val)  return false;
            return compare(T1->left, T2->left) && compare(T1->right, T2->right);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

