#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string output;
        string srt;
        string lng;

        if (a.length() > b.length())
        {
            lng = a;
            srt = b;
        }
        else
        {
            srt = a;
            lng = b;
        }

        int carry = 0;
        for (size_t i = 0; i < lng.length(); i++)
        {
            int left = (int)(lng[lng.length() - 1 - i] - '0');
            int right = i < srt.length() ? (int)(srt[srt.length() - 1 - i] - '0') : 0;
            int sum = left + right + carry;

            if (sum == 1 || sum == 3)
            {
                output.insert(0, "1");
            }
            else
            {
                output.insert(0, "0");
            }

            carry = carry + left + right > 1 ? 1 : 0;
        }

        if (carry > 0)
        {
            output.insert(0, "1");
        }

        return output;
    }
};