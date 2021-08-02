//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
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
//  [20,9],
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
// Related Topics 树 广度优先搜索 
// 👍 86 👎 0

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

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
        vector<vector<int>> levelOrder_1(TreeNode *root)
        {

            // o(n)
            if (root == nullptr)
            { return {}; }

            vector<vector<int>> ans;
            deque<TreeNode *> q;
            q.push_back(root);
            bool lrFlag = true;

            while(!q.empty())
            {
                // 保存每层的元素
                vector<int> container;
                TreeNode *cur;
                for (int i = q.size(); i > 0; --i)
                {
                    if (lrFlag)
                    {
                        cur = q.front();
                        q.pop_front();
                        if (cur->left)
                        { q.push_back(cur->left); }
                        if (cur->right)
                        { q.push_back(cur->right); }
                    }
                    else
                    {
                        cur = q.back();
                        q.pop_back();
                        if (cur->right)
                        { q.push_front(cur->right); }
                        if (cur->left)
                        { q.push_front(cur->left); }
                    }
                    container.push_back(cur->val);
                }
                lrFlag = !lrFlag;
                ans.push_back(container);
            }
            return ans;
        }

        vector<vector<int>> levelOrder(TreeNode *root)
        {
            // o(n)
            if (root == nullptr)
            { return {}; }

            vector<vector<int>> ans;
            queue<TreeNode *> q;
            q.push(root);

            while(!q.empty())
            {
                // 保存每层的元素
                vector<int> container;
                TreeNode *cur;
                for (int i = q.size(); i > 0; --i)
                {
                    cur = q.front();
                    q.pop();
                    if (cur->left)
                    { q.push(cur->left); }
                    if (cur->right)
                    { q.push(cur->right); }

                    container.push_back(cur->val);
                }
                if (ans.size() & 1)
                {
                    std::reverse(container.begin(), container.end());
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