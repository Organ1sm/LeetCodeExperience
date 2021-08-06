#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        Node *connect(Node *root)
        {
            if(root == nullptr) return root;

            Node *pre = root;
            Node *cur = nullptr;

            while(pre->left != nullptr)
            {
                cur = pre;
                while(cur != nullptr)
                {
                    cur->left->next = cur->right;

                    if(cur->next) cur->right->next = cur->next->left;

                    cur = cur->next;
                }

                pre = pre->left;
            }

            return root;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

