#include <iostream>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int s2[256] = {0};
    for (int i = 0; i < magazine.length(); i++)
    {
        s2[(int)magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        s2[(int)ransomNote[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (s2[i] < 0)
            return false;
    }
    return true;
}

int main()
{
    // Test
    return 0;
}