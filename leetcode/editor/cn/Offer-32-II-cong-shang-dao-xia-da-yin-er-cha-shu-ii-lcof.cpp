//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
//
// 注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-tra
//versal/ 
// Related Topics 树 广度优先搜索 
// 👍 92 👎 0

#include <iostream>
#include <vector>
#include <queue>

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
        vector<vector<int>> levelOrder(TreeNode *root)
        {
            // o(n)
            if (root == nullptr)
            { return {}; }

            queue<TreeNode *> q;
            q.push(root);
            vector<vector<int>> ans;
            ans.push_back({root->val});
            while(!q.empty())
            {
                // 保存每层的元素
                vector<int> container;

                for (int i = q.size(); i > 0; --i)
                {
                    TreeNode *cur = q.front();
                    container.push_back(cur->val);
                    q.pop();

                    if (cur->left)
                    { q.push(cur->left); }
                    if (cur->right)
                    { q.push(cur->right); }
                }
                ans.push_back(container);
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}