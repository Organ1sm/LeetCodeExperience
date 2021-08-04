#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
        int countNodes(TreeNode* root)
        {
            if(root == nullptr) return 0;

            return countNodes(root->left) + countNodes(root->right) + 1;
        }
};
class Solution
{
    public:
        int countNodes(TreeNode* root)
        {
            if(root == nullptr) return 0;
            int level = 0;

            TreeNode *cur = root;
            while(cur->left)
            {
                ++level;
                cur = cur->left;
            }

            int low = 1 << level;
            int high = (1 << (level + 1)) - 1;

            while(low < high)
            {
                int mid =  (high - low + 1) / 2 + low;
                if(exist(root, level, mid))
                    low = mid;      // 因为第mid + 1个节点可能不存在
                    else
                        high = mid - 1;
            }


            return low;
        }

        bool exist(TreeNode* root, int level, int k)
        {
            // 第h层的节点最多有2^h个，所以有h+1位
            // 第h+1位的值 ->  2^h 从第h位开始校验
            // 所以掩码的值为 -> 2^(h-1)
            int mask = 1 << (level - 1);

            TreeNode *cur = root;
            while(cur != nullptr && mask > 0)
            {
                if(!(mask & k))
                    cur = cur->left;
                else
                    cur = cur->right;

                mask >>= 1;
            }

            return cur != nullptr;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

