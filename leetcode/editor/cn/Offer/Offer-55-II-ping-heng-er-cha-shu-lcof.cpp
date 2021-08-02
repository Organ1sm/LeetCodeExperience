//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。 
//
// 
//
// 示例 1: 
//
// 给定二叉树 [3,9,20,null,null,15,7] 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回 true 。 
// 
//示例 2: 
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4] 
//
// 
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 
//
// 返回 false 。 
//
// 
//
// 限制： 
//
// 
// 0 <= 树的结点个数 <= 10000 
// 
//
// 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/ 
//
// 
// Related Topics 树 深度优先搜索 
// 👍 141 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution
{
    public:
        bool isBalanced(TreeNode *root)
        {
            // 先序遍历
//            if(root == nullptr) return true;
//            return std::abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 &&
//                   isBalanced(root->left) &&isBalanced(root->right);
            // 后续遍历
            return recur(root) != -1;
        }

        int recur(TreeNode *node)
        {
            // 若为平衡树 返回以node为根节点的树深度
            // 否则返回-1
            if (node == nullptr)
            { return 0; }

            int left = recur(node->left);
            if (left == -1)
            { return -1; }

            int right = recur(node->right);
            if (right == -1)
            { return -1; }

            if (std::abs(left - right) <= 1)
            {
                return std::max(left, right) + 1;
            }
            else
            {
                return -1;
            }
        }

        int maxDepth(TreeNode *root)
        {
            if (root == nullptr)
            { return 0; }

            return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}