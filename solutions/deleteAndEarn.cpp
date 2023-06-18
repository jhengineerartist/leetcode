#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int total_val = 0;
        // value, occurrences
        unordered_map<int, int> total_value_table;
        int max_value = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            max_value = max(max_value, nums[i]);
            if (total_value_table.find(nums[i]) != total_value_table.end())
            {
                total_value_table[nums[i]] += nums[i];
            }
            else
            {
                total_value_table[nums[i]] = nums[i];
            }
        }

        int earnings[max_value + 1];
        earnings[0] = 0;
        earnings[1] = total_value_table.find(1) != total_value_table.end() ? total_value_table[1] : 0;

        for (int i = 2; i <= max_value; i++)
        {
            int gain_for_num = total_value_table.find(i) != total_value_table.end() ? total_value_table[i] : 0;
            earnings[i] = max(earnings[i - 1], earnings[i - 2] + gain_for_num);
        }

        return earnings[max_value];
    }
};