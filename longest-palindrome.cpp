#include <iostream>  

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int count[256] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            count[(int)s[i]]++;
        }
        int odd = 0;
        for (int i = 0; i < 256; i++)
        {
            if (count[i] % 2)
                odd++;
        }
        if (odd == 1 || odd == 0)
            return s.length();
        return s.length() - odd + 1;
    }
};