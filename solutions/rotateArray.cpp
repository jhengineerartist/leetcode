#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        for (size_t i = 1; i <= nums.size(); i++)
        {
            swap(nums[k % nums.size()], nums[(i + k) % nums.size()]);
        }
    }
};