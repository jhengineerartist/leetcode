#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        bool is_valid = s.length() % 2 == 0;

        size_t i = 0;
        vector<char> parenstack;
        while (is_valid && i < s.length())
        {
            if (s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{')
            {
                parenstack.push_back(s[i]);
            }
            else if (s[i] == ')' ||
                     s[i] == ']' ||
                     s[i] == '}')
            {
                if (parenstack.size() == 0 ||
                    (s[i] == ')' && parenstack.back() != '(') ||
                    (s[i] == ']' && parenstack.back() != '[') ||
                    (s[i] == '}' && parenstack.back() != '{'))
                {
                    is_valid = false;
                }
                else
                {
                    parenstack.pop_back();
                }
            }
            i++;
        }

        return is_valid && parenstack.size() == 0;
    }
};