#include <iostream>
#include <vector>

using namespace std;

class Solution1 { // O(n)
public:
    int maxiumSubarray(vector<int> &nums){
        int sum1 = 0;
        int sum2 = -10000;
        for(int i = 0; i < nums.size(); i++){
            sum1 += nums[i];
            sum2 = (sum2 > sum1) ? sum2 : sum1;
            if(sum1 < 0) sum1 = 0;
        }
        return sum2;
    }

};