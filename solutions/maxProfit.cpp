#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<pair<int, int>> prices_with_day;

        auto price_gtr_than_fnc = [](pair<int, int> day_price1, pair<int, int> day_price2)
        {
            return day_price1.second > day_price2.second;
        };

        for (int i = 0; i < prices.size(); i++)
        {
            prices_with_day.push_back(make_pair(i, prices[i]));
        }

        sort(prices_with_day.begin(), prices_with_day.end(), price_gtr_than_fnc);

        vector<pair<int, int>> only_increasing_days;
        int latest_day = -1;
        for (pair<int, int> &day : prices_with_day)
        {
            if (day.first > latest_day)
            {
                latest_day = day.first;
                only_increasing_days.push_back(day);
            }
        }

        vector<int> max_profits;
        int max_price_day_index = 0;
        for (int day = 0; day < prices.size(); day++)
        {
            if (day > only_increasing_days[max_price_day_index].first)
            {
                max_price_day_index++;
            }
            max_profits.push_back(only_increasing_days[max_price_day_index].second - prices[day]);
        }

        int largest = -1;
        for (int profit : max_profits)
        {
            largest = largest < profit ? profit : largest;
        }

        return largest;
    }
};

int main()
{
    vector<int> test_case1 = {7, 1, 5, 3, 6, 4};
    Solution sln;
    int profit = sln.maxProfit(test_case1);
    return 0;
}