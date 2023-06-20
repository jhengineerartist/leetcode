#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int hi = nums.size() - 1;
        int lo = 0;

        while (lo < hi)
        {
            while (lo < hi && nums[hi] == val)
            {
                hi--;
            }
            if (nums[lo] == val)
            {
                swap(nums, lo, hi);
            }
            lo++;
        }
        size_t i = 0;
        while (nums[i] != val && i < nums.size())
        {
            i++;
        }
        return i;
    }
    void swap(vector<int> &elements, int loc1, int loc2)
    {
        int temp = elements[loc1];
        elements[loc1] = elements[loc2];
        elements[loc2] = temp;
    }
};