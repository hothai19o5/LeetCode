#include <iostream>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

class Solution { // O(n*log(n))
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<double, int> khoang_cach_so_voi_goc;
        for(int i = 0; i < points.size(); i++) {
            double khoang_cach = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            khoang_cach_so_voi_goc.insert(make_pair(khoang_cach, i));
        }
        vector<vector<int>> result;
        for(pair<double, int> it : khoang_cach_so_voi_goc) {
            result.push_back(points[it.second]);
            k--;
            if(k == 0) break;
        }
        return result;
    }
};