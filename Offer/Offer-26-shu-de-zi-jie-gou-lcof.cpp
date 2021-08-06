//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 
//给定的树 A: 
//
// 3 
// / \ 
// 4 5 
// / \ 
// 1 2 
//给定的树 B： 
//
// 4 
// / 
// 1 
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
// Related Topics 树 
// 👍 232 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution
{
    public:
        // 给的是树的中序遍历
        bool isSubStructure(TreeNode *A, TreeNode *B)
        {
            if (A == nullptr || B == nullptr)
            { return false; }

            return contain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }

        bool contain(TreeNode *T1, TreeNode *T2)
        {
            if (T2 == nullptr)  // T2已匹配完
            { return true; }
            if (T1 == nullptr || T1->val != T2->val)  // T1未找到T2
            { return false; }

            // 此节点已经匹配成功，所以需要匹配到左子树和右子树

            return contain(T1->left, T2->left) && contain(T1->right, T2->right);
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}