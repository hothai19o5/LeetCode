#include <iostream>

using namespace std;

bool isBadVersion(int n){
    // API
}

int firstBadVersion(int n){
    int start = 1;
    int end = n;
    int result = 0;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(isBadVersion(mid)){
            result = mid;
            end = mid - 1;      
        }else{
            start = mid + 1;
        }
    }
    return result;
}

int main(){
    // Test
    return 0;
}