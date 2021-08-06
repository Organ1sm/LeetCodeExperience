#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    private:
        vector <string> ans;

        void traversal(TreeNode *cur, vector<int> &path)
        {
            path.push_back(cur->val);
            if (cur->left == nullptr && cur->right == nullptr)
            {
                string spath;
                for (int i = 0; i < path.size() - 1; ++i)
                {
                    spath += std::to_string(path[i]);
                    spath += "->";
                }
                spath += std::to_string(path[path.size() - 1]);
                ans.emplace_back(spath);

                return;
            }

            if (cur->left)
            {
                traversal(cur->left, path);
                path.pop_back();
            }

            if (cur->right)
            {
                traversal(cur->right, path);
                path.pop_back();
            }
        }

    public:
        vector <string> binaryTreePaths(TreeNode *root)
        {
            if (root == nullptr)
            { return {}; }
            vector<int> path;
            traversal(root, path);

            return ans;
        }
};

class Solution1
{
    private:
        vector <string> ans;

        void traversal(TreeNode *cur, string path)
        {
            path += std::to_string(cur->val);
            if (cur->left == nullptr && cur->right == nullptr)
            {
                ans.emplace_back(path);
                return;
            }

            if (cur->left)
            {
                traversal(cur->left, path + "->");
            }

            if (cur->right)
            {
                traversal(cur->right, path + "->");
            }
        }

    public:
        vector <string> binaryTreePaths(TreeNode *root)
        {
            if (root == nullptr)
            { return {}; }
            string path;
            traversal(root, path);

            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

