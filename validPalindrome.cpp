#include <iostream>

using namespace std;

bool isValid(string s)
{
    string myString = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (((int)s[i] >= 97) && ((int)s[i] <= 122))
        {
            myString += (char)s[i];
        }
        else if (((int)s[i] >= 65 && (int)s[i] <= 90))
        {
            s[i] = char((int)s[i] + 32);
            myString += (char)s[i];
        }
    }
    cout << myString << endl;
    for (int i = 0; i < myString.length(); i++)
    {
        if (myString[i] != myString[myString.length() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    // Test
    string s = "A man, a plan, a canal: Panama";
    if (isValid(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}