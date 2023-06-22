#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> sanitized;

        for (auto &character : s)
        {
            if (isalnum(character))
            {
                sanitized.push_back(tolower(character));
            }
        }

        int i = 0;
        int j = sanitized.size() - 1;

        bool is_palen = true;
        while (is_palen && i <= j)
        {
            is_palen = sanitized[i] == sanitized[j];
            i++;
            j--;
        }

        return is_palen;
    }
};