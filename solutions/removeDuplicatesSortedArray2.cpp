#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last_filtered = 0;
        int occurrences = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                occurrences++;
            }
            else
            {
                occurrences = 1;
            }

            if (occurrences <= 2)
            {
                last_filtered++;
                nums[last_filtered] = nums[i];
            }
        }

        return last_filtered + 1;
    }
};

int main()
{
    vector<int> test_case_1 = {1, 1, 1, 2, 2, 3};
    Solution sln;
    int result = sln.removeDuplicates(test_case_1);
    return 0;
}