#include <iostream>
#include <vector>
#include "../include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution
{
    public:
        void reorderList1(ListNode *head)
        {
            // O(N)
            // O(N)
            if(head == nullptr) return;

            std::vector<ListNode*> vec;

            ListNode *cur = head;
            while(cur != nullptr)
            {
                vec.emplace_back(cur);
                cur = cur->next;
            }

            int left  = 0;
            int right = vec.size() - 1;

            while(left < right)
            {
                vec[left]->next = vec[right];
                left++;
                if(left == right) break;
                vec[right]->next = vec[left];
                right--;
            }

            vec[left]->next = nullptr;
        }

        void reorderList(ListNode *head)
        {
            if(head == nullptr) return;

            ListNode *mid = middleNode(head);
            ListNode *l1 = head;
            ListNode *l2 = mid->next;
            // 断开连接
            mid->next = nullptr;
            l2 = reverse(l2);
            mergeList(l1, l2);
        }
        ListNode * middleNode(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;

            while(fast->next != nullptr && fast->next->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        ListNode* reverse(ListNode *head)
        {
            ListNode *cur = head;
            ListNode *pre = nullptr;
            ListNode *tmp = nullptr;

            while(cur != nullptr)
            {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }

            return pre;
        }
        
        void mergeList(ListNode *l1, ListNode *l2)
        {
            ListNode *l1Tmp = nullptr;
            ListNode *l2Tmp = nullptr;

            while(l1 != nullptr && l2 != nullptr)
            {
                l1Tmp = l1->next;
                l2Tmp = l2->next;

                l1->next = l2;
                l1 = l1Tmp;

                l2->next = l1;
                l2 = l2->tmp;
            }
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;

    return 0;
}