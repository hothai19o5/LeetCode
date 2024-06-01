#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int min_len = strs[0].length();
        for(int i = 0; i < n; i++){
            if(min_len > strs[i].length()) min_len = strs[i].length();
        }
        string result = "";
        for(int i = 0; i < min_len; i++){
            for(int j = 0; j < n-1; j++){
                if(strs[j][i] != strs[j+1][i]) return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};