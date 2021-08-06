#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}

};

class Solution
{
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *p1 = l1;
            listNode *p2 = l2;
            ListNode *pre = nullptr;
            int carry = 0;

            while(p1 || p2)
            {
                // 没有就补0
                int a = p1 ? p1->val : 0;
                int b = p2 ? p2->val : 0;
                int sum = a + b + carry;

                if (p1)
                {   // l1的长度大于l2
                    p1->val = sum % 10;
                }
                else
                {
                    // l2的长度大于l1
                    pre->next = new ListNode(sum % 10);     // 这里p1已经空，需要记录前结点防止断开
                    p1 = pre->next;
                }
                // 记录进多少位
                carry = sum / 10;

                pre = p1;
                p1 = p1->next;
                if (p2)
                { p2 = p2->next; }

            }
            pre->next = carry ? new ListNode(1) : nullptr;
            return l1;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << "Hello LeetCode" << endl;
}