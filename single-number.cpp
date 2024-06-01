#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        for(int i = 1; i < n; i++){
            result ^= nums[i];
        }
        return result;
    }
};