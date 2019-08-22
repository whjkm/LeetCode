#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//贪心，按开始时间排序
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 1) return 0;
        sort(points.begin(), points.end());
        int count = 1, arrow = points[0][1];
        for(int i = 1; i < points.size(); ++i)
        {
            if(arrow > points[i][1])
            {
                arrow = points[i][1];
            }
            else if(arrow < points[i][0])
            {
                arrow = points[i][1];
                count ++;
            }
        }
        return count;
    }
};


// 贪心, 按照end时间排序
/*
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 1) return 0;
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), cmp);
        for(auto & point : points)
        {
            if(arrow != INT_MIN && point[0] <= arrow) continue;
            arrow = point[1];
            count ++;
        }
        return count;
    }
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
     }
};
*/

/*
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() < 1) return 0;
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), cmp);
        for(int i = 0; i < points.size(); ++i)
        {
            if(arrow != INT_MIN && points[i].first <= arrow) continue;
            arrow = points[i].second;
            count++;
        }
        return count;
    }
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
};
*/

int main()
{
    Solution s;
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    int count = s.findMinArrowShots(points);
    cout << count << endl;
    return 0;
}
