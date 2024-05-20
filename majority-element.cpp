#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// Cách 1, O(nlogn)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(int)nums.size()/2];
    }
};
// Cách 2, sử dụng hashmap
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            myMap[nums[i]]++;
        }
        int n = nums.size()/2 + 1;
        for(auto i : myMap){
            if(i.second >= n) return i.first;
        }
        return 0;
    }
};
// Cách 3, sử dụng thuật toán Moore Voting, O(n)
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0) {
                candidate = nums[i];
                count++;
            }
            else if(candidate != nums[i]) count--;
            else if(candidate == nums[i]) count++;
        }
        return candidate;
    }
};