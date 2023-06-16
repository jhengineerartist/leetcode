#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last_filtered = 0;
        int previous_element = -101;
        int current = 0;
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

int main()
{
    vector<int> test_case_1 = {1, 1, 2};
    Solution sln;
    int result = sln.removeDuplicates(test_case_1);
    return 0;
}