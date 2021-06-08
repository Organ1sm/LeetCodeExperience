#include <iostream>
#include <vector>
#include "include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        ListNode *reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *newHead = new ListNode(-1);
            newHead->next = head;

            ListNode *start{newHead};
            for (int i = 0; i < left - 1; i++)
                start = start->next;

            ListNode *leftNode = start->next;
            ListNode *rightNode = start;
            for (int i = 0; i < right - left + 1; i++)
                rightNode = rightNode->next;

            // 保存right后的节点
            ListNode *end = rightNode->next;

            // 切断链表
            start->next = nullptr;
            rightNode->next = nullptr;

            // 重新链接
            start->next = reverse(leftNode);
            leftNode->next = end;

            return newHead->next;
        }

        ListNode *reverse(ListNode *head)
        {
            ListNode *prev = head;
            ListNode *cur = head->next;

            while(cur != nullptr)
            {
                ListNode *temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }

            return prev;
        }
};

int main()
{

    auto node5 = new ListNode(5);

    Solution s;
    s.reverseBetween(node5, 1, 1);
}
//leetcode submit region end(Prohibit modification and deletion)

