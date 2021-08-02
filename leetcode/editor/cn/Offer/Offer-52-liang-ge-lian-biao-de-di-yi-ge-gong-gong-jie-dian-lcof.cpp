#include <iostream>
#include <vector>
#include "../include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            ListNode *curA = headA;
            ListNode *curB = headB;

            while(curA != curB)
            {
                curA = curA != nullptr ? curA->next : headB;
                curB = curB != nullptr ? curB->next : headA;
            }

            return curA;
        }
};
//leetcode submit region end(Prohibit modification and deletion)
