//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 链表 
// 👍 115 👎 0

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr)
    {}
};

class Solution
{
    public:
        vector<int> reversePrintUseIterator(ListNode *head)
        {
            if (head == nullptr)
            {
                return {};
            }
            ListNode *cur = head;
            int size = 0;
            while(cur != nullptr)
            {
                cur = cur->next;
                ++size;
            }

            vector<int> revContainer;
            revContainer.resize(size);
            cur = head;
            for (auto it = revContainer.rbegin(); it != revContainer.rend(); it++)
            {
                *it = cur->val;
                cur = cur->next;
            }
            return revContainer;
        }

        vector<int> reversePrintUseStack(ListNode *head)
        {
            vector<int> container;
            stack<int> s;
            ListNode *cur = head;

            while(head)
            {
                s.push(cur->val);
                cur = cur->next;
            }
            while(!s.empty())
            {
                container.push_back(s.top());
                s.pop();
            }
            return container;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}