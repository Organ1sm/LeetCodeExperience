#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
        vector<int> largestValues(TreeNode* root)
        {
            std::vector<int> ans;
            queue<TreeNode *> q;
            if(root != nullptr) q.push(root);

            while(!q.empty())
            {
                auto size = q.size();
                int maxValue = INT_MIN;

                for(int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front();
                    q.pop();
                    maxValue = std::max(maxValue, cur->val);

                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }

                ans.push_back(maxValue);

            }

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

