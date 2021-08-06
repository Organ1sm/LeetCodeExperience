#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        vector <vector<int>> levelOrder(Node *root)
        {
            std::vector<std::vector<int>> ans;
            queue<Node*> q;
            if(root != nullptr) q.push(root);

            while (!q.empty())
            {
                auto size = q.size();
                std::vector<int> v;

                for(int i = 0; i < size; i++)
                {
                    Node *cur = q.front();
                    q.pop();

                    v.emplace_back(cur->val);
                    for(auto &e : cur->children)
                        if(e) q.push(e);
                }

                ans.emplace_back(v);
            }
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

