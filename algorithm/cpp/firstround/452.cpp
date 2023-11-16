#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points);
};

int Solution::findMinArrowShots(vector<vector<int>>& points) 
{
    if(points.size()<2) return points.size();

    sort(points.begin(), points.end());

    int res = 1;
    //前一个重叠区间的起始和终止坐标
    int preStart = points[0][0];
    int preEnd = points[0][1];

    for(int i=1; i<points.size(); i++)
    {
        if(points[i][0]>preEnd)  //不相交，更新重叠区间
        {
            preStart = points[i][0];
            preEnd = points[i][1];
            res++;
        }
        else
        {
            preStart = max(preStart, points[i][0]);
            preEnd = min(preEnd, points[i][1]);
        }
    }
    return res;
}