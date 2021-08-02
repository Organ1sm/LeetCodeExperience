//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的
//功能。(若队列中没有元素，deleteHead 操作返回 -1 ) 
//
// 
//
// 示例 1： 
//
// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
// 
//
// 示例 2： 
//
// 输入：
//["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
// 
//
// 提示： 
//
// 
// 1 <= values <= 10000 
// 最多会对 appendTail、deleteHead 进行 10000 次调用 
// 
// Related Topics 栈 设计 
// 👍 199 👎 0

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class CQueue
{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        CQueue()
        {
            while(!s1.empty())
            { s1.pop(); }
            while(!s2.empty())
            { s2.pop(); }
        }

        void appendTail(int value)
        {
            s1.push(value);
        }

        int deleteHead()
        {
            int deleteEle = -1;
            if (s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            // 此时s1,s2都没元素
            if (s2.empty())
            {
                return -1;
            }

            deleteEle = s2.top();
            s2.pop();
            return deleteEle;
        }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}