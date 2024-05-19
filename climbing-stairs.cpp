class Solution {
public:
    int array[46] = {0};
    int climbStairs(int n) { 
        if(n==1) return 1;
        if(n==2) return 2;
        array[1] = 1;
        array[2] = 2;
        for(int i = 3; i <= 45; i++){
            array[i] = array[i-1]+array[i-2];
            if(i == n) return array[i];
        }
        return array[n];
    }
};