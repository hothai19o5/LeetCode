#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resultIntervals;
        int i = 0;
        // Thêm những phần tử nhỏ hơn newInterval
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            resultIntervals.push_back(intervals[i]);
            i++;
        }
        // Cập nhật lại newInterval theo các phần tử giao với newInterval
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        resultIntervals.push_back(newInterval);
        // Thêm những phần tử lớn hơn newInterval
        while(i < intervals.size() && intervals[i][0] > newInterval[1]) {
            resultIntervals.push_back(intervals[i]);
            i++;
        }

        return resultIntervals;
    }
};

