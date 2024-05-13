#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> myMap;
    for(int i = 0; i < nums.size(); i++){
        myMap.insert(make_pair(nums[i], i));
        int temp = target - nums[i];
        if((myMap.count(temp) > 0) && (myMap[temp] != i)){
            vector<int> result = {myMap[temp], i};
            return result;
        }
    }
    return {};
}

int main(){
    vector<int> nums = {3,3};
    vector<int> myVector = twoSum(nums, 6);
    cout << "[" << myVector[0] << "," << myVector[1] << "]";
}