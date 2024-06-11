#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 { // Kadane 
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

class Solution2 {   // divide and conquer
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    int maxSubArray(vector<int>& nums, int L, int R) {
        if(L > R) return INT_MIN;

        int leftSum = 0, rightSum = 0, curSum, mid = (L + R)/2;

        for(int i = mid - 1, curSum = 0; i >= L; i--) {
            curSum += nums[i];
            leftSum = max(curSum, leftSum);
        }

        for(int i = mid + 1, curSum = 0; i <= R; i++) {
            curSum += nums[i];
            rightSum = max(curSum, rightSum);
        }

        return max({maxSubArray(nums, L, mid - 1), maxSubArray(nums, mid + 1, R), leftSum + nums[mid] + rightSum});
    }
};