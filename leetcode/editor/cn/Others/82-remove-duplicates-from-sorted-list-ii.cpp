#include <iostream>
#include <vector>
#include "../include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        ListNode *deleteDuplicates(ListNode *head)
        {
            if(head == nullptr) return head;

            ListNode *dummy = new ListNode(-1, head);
            ListNode *cur   = dummy;

            while(cur->next && cur->next->next)
            {
                if(cur->next->val == cur->next->next->val)
                {
                    int x = cur->next->val;
                    while(cur->next && cur->next->val = x)
                        cur->next = cur->next->next;
                }
                else
                {
                    cur = cur->next;
                }
            }

            return dummy->next;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

