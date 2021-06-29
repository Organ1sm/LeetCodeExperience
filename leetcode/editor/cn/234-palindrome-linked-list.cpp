#include <iostream>
#include <vector>
#include "include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool isPalindrome(ListNode *head)
        {
            if (head == nullptr) return true;

            ListNode* firstEnd = middleNode(head);
            ListNode* secondStart = reverseList(firstEnd->next);

            ListNode *l1 = head;
            ListNode *l2 = secondStart;

            while(l2 != nullptr)
            {
                if(l1->val != l2->val)
                    return false;

                l1 = l1->next;
                l2 = l2->next;
            }
            firstEnd->next = reverseList(secondStart);
            return true;
        }

        ListNode* reverseList(ListNode *head)
        {
            ListNode *prev = nullptr;
            ListNode *cur  = head;

            while(cur != nullptr)
            {
                ListNode *temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }

            return prev;
        }

        ListNode *middleNode(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;

            while(fast->next != nullptr && fast->next->next != nullptr)
            {
                slow = slow ->next;
                fast = fast->next->next;
            }
            return slow;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

