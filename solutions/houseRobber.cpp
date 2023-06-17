#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        unordered_map<int, int> max_rob_for_addr;
        return maxRobberyForAddr(max_rob_for_addr, nums, nums.size() - 1);
    }

    int maxRobberyForAddr(unordered_map<int, int> &max_rob_for_addr, vector<int> &nums, int addr)
    {
        // Base Case
        int max_robbery = 0;
        if (addr >= 0)
        {
            int max_prev = 0;
            int max_current = 0;

            if (max_rob_for_addr.find(addr - 2) == max_rob_for_addr.end())
            {
                max_rob_for_addr[addr - 2] = maxRobberyForAddr(max_rob_for_addr, nums, addr - 2);
            }

            if (max_rob_for_addr.find(addr - 1) == max_rob_for_addr.end())
            {
                max_rob_for_addr[addr - 1] = maxRobberyForAddr(max_rob_for_addr, nums, addr - 1);
            }
            max_current = nums[addr] + max_rob_for_addr[addr - 2];
            max_prev = max_rob_for_addr[addr - 1];

            max_robbery = max(max_current, max_prev);
        }
        return max_robbery;
    }
};