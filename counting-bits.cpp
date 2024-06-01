#include <iostream>
#include <vector>

using namespace std;

class Solution1 {   // Sử dụng hàm dựng sẵn
public:
    vector<int> countBits(int n){
        vector<int> result;
        for(int i = 0; i <= n; i++){
            result.push_back(__builtin_popcount(i));
        }
        return result;
    }
};

class Solution1 {   // Sử dụng hàm countSetBits tự tạo
public:
    vector<int> countBits(int n){
        vector<int> result;
        for(int i = 0; i <= n; i++){
            result.push_back(countSetBits(i));
        }
        return result;
    }
    int countSetBits(int n){
        int count = 0;
        while(n > 0){
            count += (n & 1);
            n >>= 1;
        }
    }
};

class Solution1 {   
    /*Số lượng bit '1' trong một số i có thể được tính dựa trên 
    số lượng bit '1' trong số i/2 (dịch phải i một bit) cộng thêm 1 nếu bit cuối của i là 1.*/
public:
    vector<int> countBits(int n){
        vector<int> result(n+1);
        result[0] = 0;
        for(int i = 1; i <= n; i++){
            result[i] = result[i>>1] + (i&1);
        }
        return result;
    }
};
