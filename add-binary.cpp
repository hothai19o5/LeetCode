#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b){
        int a_length = a.length() - 1; int b_length = b.length() - 1;
        int carry = 0; string result = "";
        while(a_length >= 0 || b_length >= 0 || carry == 1) {
            if(a_length >= 0){
                carry += a[a_length] - '0';
                a_length--;
            }if(b_length >= 0){
                carry += b[b_length] - '0';
                b_length--;
            }
            result = (char)(carry%2 + "0") + result;
            carry /= 2;
        }
        return result;
    }
};