#include "maxScoreMultiplicationDP.cpp"
#include <vector>
// Use this as a quick way to run whatever problem
// I'm working on

int main()
{
    vector<int> nums = {-5, -3, -3, -2, 7, 1};
    vector<int> multipliers = {-10, -5, 3, 4, 6};
    Solution sln;
    int score = sln.maximumScore(nums, multipliers);
    return score;
}