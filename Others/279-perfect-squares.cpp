#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    public:
        int numSquares(int n)
        {
            int ret = 1;

            for (int i = 1; i * i <= n; i++) storage.insert(i * i);

            while(ret <= 4)
            {
                if (divisible(ret, n))
                { return ret; }

                ret++;
            }

            return 0;
        }

        bool divisible(int count, int value)
        {
            if (count == 1)
            { return storage.find(value) != storage.end(); }
            else
            {
                for (const int ele : storage)
                {
                    if (divisible(count - 1, value - ele))
                    { return true; }
                }
            }

            return false;
        }


    private:
        std::unordered_set<int> storage;

};
//leetcode submit region end(Prohibit modification and deletion)

