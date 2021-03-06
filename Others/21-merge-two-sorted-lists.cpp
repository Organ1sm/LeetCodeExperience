#include <iostream>
#include <vector>
#include "../include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
        {
            ListNode *newHead = new ListNode(-1);

            ListNode *cur = newHead;
            while(l1 != nullptr && l2 != nullptr)
            {
                if (l1->val <= l2->val)
                {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }

            cur->next = l1 == nullptr ? l2 : l1;
            return newHead->next;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

