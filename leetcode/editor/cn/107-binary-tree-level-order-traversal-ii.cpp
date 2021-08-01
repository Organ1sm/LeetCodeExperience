#include <iostream>
#include <vector>
#include "include/TreeNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        vector <vector<int>> levelOrderBottom(TreeNode *root)
        {
            queue < TreeNode * > q;
            std::vector <std::vector<int>> ans;

            if (root != nullptr)
            { q.push(root); }

            while(!q.empty())
            {
                auto size = q.size();
                std::vector<int> v;

                for (int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front();
                    q.pop();

                    v.emplace_back(cur->val);
                    if(cur->left)  q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }

                ans.emplace_back(v);
            }

            std::reverse(ans.begin(), ans.end());

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

