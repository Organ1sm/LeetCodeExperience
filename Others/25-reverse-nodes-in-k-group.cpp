#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(): val(0), next(nullptr)
    {}

    ListNode(int x): val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next): val(x), next(next)
    {}
};

class Solution
{
    public:
        ListNode *reverseKGroup(ListNode *head, int k)
        {
            ListNode *dummy = new ListNode(-1, head);

            ListNode *pre = dummy;
            ListNode *end = dummy;
            while(end->next != nullptr)
            {
                for (int i = 0; i < k && end != nullptr; i++) end = end->next;
                if (end == nullptr)
                { break; }

                ListNode *start = pre->next;
                ListNode *next = end->next;

                // 断开连接
                end->next = nullptr;

                // 重新连接
                pre->next = reverse(start);
                start->next = next;

                pre = start;
                end = pre;
            }

            return dummy->next;
        }

        ListNode *reverse(ListNode *head)
        {
            ListNode *tmp = nullptr;
            ListNode *pre = nullptr;
            ListNode *cur = head;

            while(cur != nullptr)
            {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }

            return pre;
        }
};
//leetcode submit region end(Prohibit modification and deletion)
