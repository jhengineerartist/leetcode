#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last_filtered = 0;
        int previous_element = -101;
        size_t current = 0;
        while (current < nums.size())
        {
            while (current < nums.size() && nums[current] == previous_element)
            {
                current++;
            }
            if (current < nums.size())
            {
                previous_element = nums[current];
                swap(nums[current], nums[last_filtered]);
                last_filtered++;
            }
            current++;
        }
        return last_filtered;
    }
};