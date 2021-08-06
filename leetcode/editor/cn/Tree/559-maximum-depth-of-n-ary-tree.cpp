#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        int maxDepth(Node *root)
        {
            return getDepth(root);
        }

        int getDepth(Node *node)
        {
            if (node == nullptr)
            { return 0; }
            int maxDepth = 0;
            for (auto &e : node->children)
            {
                maxDepth = std::max(maxDepth, getDepth(e));
            }

            return maxDepth + 1;
        }
};

class Solution1
{
    public:
        int maxDepth(Node *root)
        {
            queue < Node * > que;
            if (root != nullptr)
            { que.push(root); }
            int depth = 0;
            while(!que.empty())
            {
                int size = que.size();
                depth++;
                for (int i = 0; i < size; i++)
                {
                    Node *node = que.front();
                    que.pop();

                    for (auto &e : node->children)
                    {
                        if (e)
                        { que.push(e); }
                    }

                }
            }

            return depth;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

