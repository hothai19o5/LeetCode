#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target){
    int start = 0, end = nums.size() - 1;
    if(nums[0] > target || nums[end] < target) return -1;
    while(start < end){
        int mid = (start + end)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main(){
    // Test
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << binarySearch(nums, target);
    return 0;
}