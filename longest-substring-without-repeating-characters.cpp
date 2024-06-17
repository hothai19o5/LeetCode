#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lengthOfLongestSubstring = 0;
        int start = 0, end = 0;
        unordered_map<char, int> charIndexMap;
        
        for(end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            // Nếu tìm thấy kí tự hiện tại trong map thì dịch chuyển start, phải thêm cả điều kiện kiểm tra xem nó có nằm trong chuỗi con đang xét hay không nữa, dịch chuyển qua kí tự bị lặp.
            if(charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }
            // Thêm key-value vào map
            charIndexMap[currentChar] = end;
            // Cập nhật lại độ dài chuỗi con
            lengthOfLongestSubstring = max(lengthOfLongestSubstring, end - start + 1);
        }
        return lengthOfLongestSubstring;
    }
};