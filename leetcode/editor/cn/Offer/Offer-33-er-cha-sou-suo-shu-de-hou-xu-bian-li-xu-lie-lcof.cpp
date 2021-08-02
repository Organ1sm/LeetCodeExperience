//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。 
//
// 
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3 
//
// 示例 1： 
//
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
// 👍 225 👎 0

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class SolutionRecur
{
    public:
        bool verifyPostorder(vector<int> &postorder)
        {
            if (!postorder.size())
            { return true; }

            return Traverse(postorder, 0, postorder.size() - 1);
        }

        bool Traverse(vector<int> &order, int start, int end)
        {
            if (start >= end)
            { return true; }

            int p = start;
            int rootValue = order[end];
            while(order[p] < rootValue)
            { ++p; };

            // 左子树最后叶节点的位置
            int leftTreeEnd = p - 1;

            while(order[p] > rootValue)
            { ++p; };

            return p == end && Traverse(order, start, leftTreeEnd) && Traverse(order, leftTreeEnd + 1, end - 1);
        }
};

class Solution
{
    public:
        bool verifyPostorder(vector<int> &postorder)
        {
            stack<int> s;
            int root = INT_MAX;

            for (int i = postorder.size() - 1; i >= 0; --i)
            {
                if (postorder[i] > root)
                { return false; }

                while(!s.empty() && postorder[i] < s.top())
                {
                    root = s.top();
                    s.pop();
                }

                s.push(postorder[i]);
            }

            return true;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{1, 3, 2, 6, 5};

    s.verifyPostorder(data);
    cout << "Hello LeetCode" << endl;
}