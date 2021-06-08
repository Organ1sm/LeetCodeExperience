//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归 
// 👍 370 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

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

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

class Solution
{
    private:
        std::unordered_map<int, int> Index; // 建立一个哈希索引表
        TreeNode *myBuildTree(const vector<int> &preorder, const vector<int> &inorder,
                              int preorderLeft, int preorderRight,
                              int inorderLeft, int inorderRight)
        {
            // 分治法的应用
            if (preorderLeft > preorderRight)
            { return nullptr; }

            // 前序遍历序列的根节点是是第一个节点,找到其位置
            int preorderRootIndex = preorderLeft;

            // 找到中序遍历序列的根节点位置
            int inorderRootIndex = Index[preorder[preorderRootIndex]];

            TreeNode *root = new TreeNode(preorder[preorderRootIndex]);

            // 计算左子树的节点个数
            int leftSubTreeSize = inorderRootIndex - inorderLeft;

            root->left = myBuildTree(preorder, inorder,
                                     preorderLeft + 1, preorderLeft + leftSubTreeSize,
                                     inorderLeft, inorderRootIndex - 1);

            root->right = myBuildTree(preorder, inorder,
                                      preorderLeft + leftSubTreeSize + 1, preorderRight,
                                      inorderRootIndex + 1, inorderRight);

            return root;
        }

    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            int n = preorder.size();
            for (int i = 0; i < n; ++i)
            {
                Index[inorder[i]] = i;
            }

            return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}