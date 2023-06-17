#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> element_counter;

        int i = 0;
        while (i < nums.size())
        {
            element_counter[nums[i]]++;
            if (element_counter[nums[i]] > nums.size() / 2)
            {
                return nums[i];
            }
            i++;
        }

        return -1;
    }
};