#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> squares(n + 1);

        for (int i = n - 1; i >= 0; i--)
        {
            int square;
            if (abs(nums[left]) < abs(nums[right]))
            {
                square = nums[right];
                right--;
            }
            else
            {
                square = nums[left];
                left++;
            }
            squares[i] = square * square;
        }
        return squares;
    }
};