#include <iostream>

using namespace std;

bool isValid(string s, string t){
    if(s.length() != t.length()) return false;
    int arr[256] = {0};
    for(int i = 0; i < s.length(); i++) arr[(int)s[i]]++;
    for(int i = 0; i < t.length(); i++) arr[(int)t[i]]--;
    for(int i = 0; i < 256; i++) if(arr[i] != 0) return false;
    return true;
}

int main(){
    // Test
    string s = "anagram", t = "nagaram";
    if(isValid(s, t)) cout << "true";
    else cout << "false";
    return 0;
}