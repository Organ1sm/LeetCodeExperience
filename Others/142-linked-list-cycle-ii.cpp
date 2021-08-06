#include <iostream>
#include <vector>
#include <unordered_set>
#include "../include/ListNode.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
lass Solution
{
    public:
        ListNode *detectCycleInHash(ListNode *head)
        {
            std::unordered_set<ListNode *> visited;

            while(head != nullptr)
            {
                if (visited.count(head) > 0)
                { return head; }

                visited.insert(head);
                head = head->next;
            }

            return nullptr;
        }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while(true)
        {
            if(fast == nullptr || fast->next == nullptr)
            { return nullptr; }

            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) break;  // 第一次相遇
        }

        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
