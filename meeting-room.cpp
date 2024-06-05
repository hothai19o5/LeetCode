#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Interval
{
    int start;
    int end;
};


class Solution {
public:
    bool canAttendMeetings(vector<Interval> &interval){
        map<int, int> myMap;
        for(int i = 0; i < interval.size(); i++){
            myMap[interval[i].start] = interval[i].end;
        }
        for(auto it = myMap.begin(), next_it = next(myMap.begin()); next_it != myMap.end(); ++it, ++next_it){
            if(it->second > next_it->second) return false;
        }
        return true;
    }
};