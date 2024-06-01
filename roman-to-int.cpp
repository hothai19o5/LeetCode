#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int len = s.length();
        int result = 0;
        if(len == 1){
            if((int)s[0] == 73) return 1;
            else if((int)s[0] == 86) return 5;
            else if((int)s[0] == 88) return 10;
            else if((int)s[0] == 76) return 50;
            else if((int)s[0] == 67) return 100;
            else if((int)s[0] == 68) return 500;
            else if((int)s[0] == 77) return 1000;
        }
        for(int i = 0; i < len - 1; i++){
            int tempi, tempj;

            if((int)s[i] == 73) tempi = 1;
            else if((int)s[i] == 86) tempi = 5;
            else if((int)s[i] == 88) tempi = 10;
            else if((int)s[i] == 76) tempi = 50;
            else if((int)s[i] == 67) tempi = 100;
            else if((int)s[i] == 68) tempi = 500;
            else if((int)s[i] == 77) tempi = 1000;

            if((int)s[i+1] == 73) tempj = 1;
            else if((int)s[i+1] == 86) tempj = 5;
            else if((int)s[i+1] == 88) tempj = 10;
            else if((int)s[i+1] == 76) tempj = 50;
            else if((int)s[i+1] == 67) tempj = 100;
            else if((int)s[i+1] == 68) tempj = 500;
            else if((int)s[i+1] == 77) tempj = 1000;

            if(tempi >= tempj) result += tempi;
            else result -= tempi;
            if(i == len - 2) result += tempj;
        }
        return result;
    }
};