#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector<double> averageOfLevels(TreeNode* root)
        {
            std::vector<double> ans;
            queue<TreeNode*> q;
            if(root != nullptr) q.push(root);

            while(!q.empty())
            {
                auto size = q.size();
                double sum = 0;

                for(int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front();
                    q.pop();

                    sum += cur->val;
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }

                ans.emplace_back(sum / size);
            }

            return ans;
        }
};

//leetcode submit region end(Prohibit modification and deletion)

