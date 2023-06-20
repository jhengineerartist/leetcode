#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int min_cost_per_stair[cost.size() + 1];
        min_cost_per_stair[0] = 0;
        min_cost_per_stair[1] = 0;

        for (size_t i = 2; i <= cost.size(); i++)
        {
            min_cost_per_stair[i] = min(min_cost_per_stair[i - 1] + cost[i - 1], min_cost_per_stair[i - 2] + cost[i - 2]);
        }

        return min_cost_per_stair[cost.size()];
    }
};