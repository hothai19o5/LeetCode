#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        long y = x;
        long reverse = 0;
        while(y > 0){
            reverse = reverse*10 + y%10;
            y /= 10;
        }
        if(reverse == x) return true;
        return false;
    }
};