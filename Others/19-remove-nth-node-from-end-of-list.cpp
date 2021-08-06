#include <iostream>
#include <vector>
#include "../include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n)
        {
            ListNode *newHead = new ListNode(-1, head);
            ListNode *former  = head;
            ListNode *latter  = head;

            for(int i = 0; i < n + 1; i++)
            {
                latter = latter->next;
            }

            while(latter != nullptr)
            {
                latter = latter->next;
                former = former->next;
            }

            ListNode *deleteNode = former->next;
            former->next = deleteNode->next;
            deleteNode->next = nullptr;
            delete deleteNode;

            return newHead->next;
        }
};
//leetcode submit region end(Prohibit modification and deletion)
