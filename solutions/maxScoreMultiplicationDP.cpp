#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct PairHash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        unordered_map<pair<int, int>, long, PairHash> memo;
        int score = scoreForCase(nums, multipliers, 0, 0, memo);
        return score;
    }

    int scoreForCase(vector<int> &n, vector<int> &m, size_t m_i, int num_start, unordered_map<pair<int, int>, long, PairHash> &memo)
    {
        int score = 0;
        int num_end = n.size() - 1 - m_i + num_start;
        if (m_i < m.size() && num_start <= num_end)
        {
            long end_subcase_score = 0;
            pair<int, int> end_pair = make_pair(m_i + 1, num_start);
            if (memo.find(end_pair) != memo.end())
            {
                end_subcase_score = memo[end_pair];
            }
            else
            {
                end_subcase_score = scoreForCase(n, m, m_i + 1, num_start, memo);
                memo[end_pair] = end_subcase_score;
            }

            long start_subcase_score = 0;
            pair<int, int> start_pair = make_pair(m_i + 1, num_start + 1);
            if (memo.find(start_pair) != memo.end())
            {
                start_subcase_score = memo[start_pair];
            }
            else
            {
                start_subcase_score = scoreForCase(n, m, m_i + 1, num_start + 1, memo);
                memo[start_pair] = start_subcase_score;
            }

            long start = n[num_start];
            long end = n[num_end];
            long mult = m[m_i];
            long end_case = end * mult + end_subcase_score;
            long start_case = start * mult + start_subcase_score;
            score = max(end_case, start_case);
        }
        return score;
    }
};