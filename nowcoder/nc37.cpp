#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


struct Interval
{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};


class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals);
};


bool compare(const Interval& s1, const Interval& s2)  //按左边界从小到大排序，若左边界相同，则按右边界从小到大排序
{
    if(s1.start<s2.start || s1.end<=s2.end) return 1;
    else return 0;
}

//时间复杂度O(NlogN)(sort时间复杂度O(NlogN),for循环遍历数组O(N)，故时间复杂度为O(NlogN))
vector<Interval> Solution::merge(vector<Interval>& intervals)
{
    if(intervals.size()<2) return intervals;
    sort(intervals.begin(), intervals.end(), compare);
    vector<Interval> res = {intervals.front()};
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i].start<= res.back().end) res.back().end = max(res.back().end, intervals[i].end);
        else res.push_back(intervals[i]);
    }
    return res;
}

int main()
{
    vector<int> v;
    if(v.size()<2)
    {
        cout<<"empty\n";
    }
    return 0;
}