//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
// 1 
// / \ 
// 2 2 
// / \ / \ 
//3 4 4 3 
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
// 1 
// / \ 
// 2 2 
// \ \ 
// 3 3 
//
// 
//
// 示例 1： 
//
// 输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
//
// 输入：root = [1,2,2,null,3,null,3]
//输出：false 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ 
// Related Topics 树 
// 👍 146 👎 0

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
        bool isSymmetric(TreeNode *root)
        {
            if (root == nullptr)
            { return true; }


            return Symmetric(root->left, root->right);
        }

        bool Symmetric(TreeNode *T1, TreeNode *T2)
        {
            if (T1 == nullptr && T2 == nullptr)
            { return true; }
            if (T1 == nullptr || T2 == nullptr)     // 一棵已空
            { return false; }

            return T1->val == T2->val && Symmetric(T1->left, T2->right) && Symmetric(T1->right, T2->left);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}