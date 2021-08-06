#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool isSameTree(TreeNode *p, TreeNode *q)
        {
            if(p == nullptr && q == nullptr) return true;
            if(p == nullptr || q == nullptr) return false;

            queue<TreeNode*> que;
            que.push(p);
            que.push(q);

            while(!que.empty())
            {
                TreeNode *T1 = que.front(); que.pop();
                TreeNode *T2 = que.front(); que.pop();

                if(!T1 && !T2) continue;
                if(T1 == nullptr || T2 == nullptr) return false;
                if(T1->val != T2->val) return false;

                que.push(T1->left);
                que.push(T2->left);
                que.push(T1->right);
                que.push(T2->right);
            }
            return true;
        }
};

class Solution
{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            return compare(p, q);
        }

        bool compare(TreeNode *T1, TreeNode *T2)
        {
            if(T1 == nullptr && T2 == nullptr) return true;
            if(T1 == nullptr || T2 == nullptr) return false;
            if(T1->val != T2->val) return false;

            return compare(T1->left, T2->left) && compare(T1->right, T2->right);
        }
};

//leetcode submit region end(Prohibit modification and deletion)

