#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        for (int i = 1; i <= nums.size(); i++)
        {
            swap(nums[k % nums.size()], nums[(i + k) % nums.size()]);
        }
    }
};

int main()
{
    vector<int> test_case1 = {1, 2, 3, 4, 5, 6, 7};
    Solution sln;
    sln.rotate(test_case1, 2);
    return 0;
}