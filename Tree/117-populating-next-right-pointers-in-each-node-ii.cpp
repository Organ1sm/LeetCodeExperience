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

            Node *cur = root;
            Node *pre = nullptr;

            while(cur != nullptr)
            {
                Node *dummy = new Node(-1);
                pre = dummy;   // pre表示下一层节点的前一个节点

                while(cur != nullptr)
                {
                    if(cur->left != nullptr)
                    {
                        pre->next = cur->left;
                        pre = pre->next;
                    }

                    if(cur->right != nullptr)
                    {
                        pre->next = cur->right;
                        pre = pre->next;
                    }

                    cur = cur->next
                }

                cur = dummy->next;
            }
            return root;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

