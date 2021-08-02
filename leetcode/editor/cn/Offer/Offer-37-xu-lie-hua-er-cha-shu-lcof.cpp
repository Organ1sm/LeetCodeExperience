//请实现两个函数，分别用来序列化和反序列化二叉树。 
//
// 示例: 
//
// 你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]" 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-b
//inary-tree/ 
// Related Topics 树 设计 
// 👍 127 👎 0

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

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

class Codec
{
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode *root)
        {

            if (root == nullptr)
            { return "[]"; }

            string s = "[";

            queue<TreeNode *> q;
            q.push(root);
            TreeNode *cur = nullptr; // 用于遍历

            while(!q.empty())
            {
                cur = q.front();
                q.pop();

                if (cur != nullptr)
                {
                    string temp = to_string(cur->val) + ",";
                    s.append(temp);
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else
                { s.append("null,"); }
            }

            s.append("]");

            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode *deserialize(string data)
        {
            if (data == "[]")
            { return nullptr; }
            vector<string> res;
            string s = data.substr(1, data.length() - 2);
            int i = 0;
            int j = 0;

            while(i < s.length())
            {
                if (s[j] != ',')
                { ++j; }
                else
                {
                    string temp = s.substr(i, j - i);
                    res.push_back(temp);
                    ++j;
                    i = j;
                }
            }

            TreeNode *root = new TreeNode(stoi(res[0]));
            TreeNode *cur = nullptr;
            i = 1;
            queue<TreeNode *> q;
            q.push(root);

            while(!q.empty())
            {
                cur = q.front();
                q.pop();

                if (res[i] != "null")
                {
                    cur->left = new TreeNode(stoi(res[i]));
                    q.push(cur->left);
                }
                ++i;
                if (res[i] != "null")
                {
                    cur->right = new TreeNode(stoi(res[i]));
                    q.push(cur->right);
                }
                ++i;

                if (i >= res.size())
                { break; }
            }

            return root;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Codec c;
    string data = "[1,2,3,null,null,4,5]";
    auto root = c.deserialize(data);
    auto res = c.serialize(root);

    cout << res << endl;

}