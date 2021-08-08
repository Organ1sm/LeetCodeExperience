#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        vector<vector<int>> ans;
        vector<int>         path;

        vector<vector<int>> pathSum(TreeNode* root, int targetSum)
        {
            if(root == nullptr) return ans;
            ans.clear();
            path.clear();

            path.emplace_back(root->val);
            traverse(root, targetSum - root->val);
            return ans;
        }

        void traverse(TreeNode *cur, int count)
        {
            if(!cur->left && !cur->right && count == 0)
                ans.emplace_back(path);

            if(!cur->left && !cur->right) return;

            if(cur->left)
            {
                path.emplace_back(cur->left->val);
                traverse(cur->left, count - cur->left->val);
                path.pop_back();
            }

            if(cur->right)
                    {
                        path.emplace_back(cur->right->val);
                        traverse(cur->right, count - cur->right->val);
                        path.pop_back();
                    }
                }
        };

//leetcode submit region end(Prohibit modification and deletion)

