#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../include/TreeNode.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    private:
        vector<int> inorder;
        vector<int> postorder;

    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
        {
            if(inorder.empty() || postorder.empty()) return nullptr;

            this->inorder = std::move(inorder);
            this->postorder = std::move(postorder);
            return buildTree(0, this->inorder.size() - 1, 0, this->postorder.size() - 1);
        }

        TreeNode *buildTree(int IB, int IE, int PB, int PE)
        {
            if (IB > IE || PB > PE) return nullptr;

            // 找到后序数组中最后一个元素
            int rootValue = this->postorder[PE];
            TreeNode *root   = new TreeNode(rootValue);


            // 找到此节点在中序数组中的位置
            auto it = std::find(this->inorder.begin(), this->inorder.end(), rootValue);
            auto rootIndex = it - this->inorder.begin();

            root->left = buildTree(IB, rootIndex - 1, PB, PB + rootIndex - IB - 1);
            root->right = buildTree(rootIndex + 1, IE, PB + rootIndex - IB, PE - 1);


            return root;
        }
};

//int main()
//{
//    Solution s;
//    vector<int> i = {4, 2, 8, 5, 9, 1, 6, 10, 3, 7};
//    vector<int> p = {4, 8, 9, 5, 2, 10, 6, 7, 3, 1};
//    s.buildTree(i, p);
//    return 0;
//}
//leetcode submit region end(Prohibit modification and deletion)

