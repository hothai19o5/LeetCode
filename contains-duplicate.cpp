#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums){
    // Sử dụng unordered map để có thể tìm kiếm phần tử với O(1)
    unordered_map<int, int> myMap;
    for(int num : nums){
        if(myMap[num] >= 1) return true;
        myMap[num]++;
    }
    return false;
}