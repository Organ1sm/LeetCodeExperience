#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    private:
        vector<int> preorder;
        unordered_map<int, int> Index;
        /// 获取前序遍历中的第一个元素得到根节点
        /// 找到根节点在中序遍历中的索引
        /// 对中序遍历划分为左子树和右子树
        /// 对后序遍历划分为左子树和右子树
        /// 递归处理左子树和右子树

        TreeNode *buildTree(int PreBeign, int PreEnd, int InBegin, int InEnd)
        {
            if(PreBeign > PreEnd || InBegin > InEnd) return nullptr;

            // 得到根节点元素
            int rootValue = this->preorder[PreBeign];
            TreeNode *root = new TreeNode(rootValue);

            int index = this->Index[rootValue];

            int leftSubTreeSize = index - InBegin;
            root->left =  buildTree(PreBeign + 1, PreBeign + leftSubTreeSize, InBegin, index - 1);
            root->right = buildTree(PreBeign + leftSubTreeSize + 1, PreEnd, index + 1, InEnd);

            return root;
        }

    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
        {
            if(preorder.empty() || inorder.empty()) return nullptr;

            this->preorder = std::move(preorder);

            int i = 0;
            for(int &e : inorder) Index[e] = i++;


            return buildTree(0, this->preorder.size() - 1, 0, inorder.size() - 1);
        }
};

//leetcode submit region end(Prohibit modification and deletion)

