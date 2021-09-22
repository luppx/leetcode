#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals);

private:
    static bool cmp(const vector<int>& a, const vector<int>& b);
};

// int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) 
// {
//     if(intervals.size()<2) return 0;

//     sort(intervals.begin(), intervals.end(), cmp);
//     // sort(intervals.begin(), intervals.end());

//     //从左往右比
//     int resLeft = 0;
//     int preEnd = intervals[0][1];
//     for (int i = 1; i < intervals.size(); i++)
//     {
//         if(intervals[i][0]<preEnd) resLeft++;
//         else preEnd = intervals[i][1];
//     }

//     //从右往左比
//     int resRight = 0;
//     int preStart = intervals.back().front();
//     for (int i = intervals.size()-2; i >= 0; i--)
//     {
//         if(intervals[i][1]>preStart) resRight++;
//         else preStart = intervals[i][0];
//     }
    
//     return min(resLeft, resRight);
// }

// bool Solution::cmp(const vector<int>& a, const vector<int>& b)
// {
//     return a[0]<b[0] || (a[0]==b[0] && a[1]<=b[1]);
// }

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    if(intervals.size()<2) return 0;

    sort(intervals.begin(), intervals.end(), cmp);

    int res = 0;
    int preEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0]<preEnd) res++;
        else preEnd = intervals[i][1];
    }
    return res;
}

//直接按照右边界排序
bool Solution::cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1]<b[1];
}

int main()
{
    vector<vector<int>> intervals = {
        {-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}
    };

    Solution obj;
    cout<<obj.eraseOverlapIntervals(intervals)<<endl;
    return 0;
}