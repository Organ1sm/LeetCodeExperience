#include <iostream>
#include <vector>
#include <unordered_set>
#include "include/ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
            // time    : O(n)
            // storage : O(n)
            unordered_set<ListNode *> seen;
            while(head != nullptr)
            {
                if (seen.count(head))
                { return true; }

                seen.insert(head);
                head  =  head->next;
            }

            return false;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

