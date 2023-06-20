#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> range_averages(nums.size(), -1);
        size_t divisor = 2 * k + 1;

        deque<int> queue;
        long running_sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            running_sum += nums[i];
            queue.push_back(nums[i]);
            if (queue.size() == divisor)
            {
                range_averages[i - k] = running_sum / divisor;
                running_sum -= queue.front();
                queue.pop_front();
            }
        }

        return range_averages;
    }
};