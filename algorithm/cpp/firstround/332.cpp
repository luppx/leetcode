#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets);

private:
    bool recur(unordered_map<string, map<string, int>>& points, int n);
    vector<string> res;
};

vector<string> Solution::findItinerary(vector<vector<string>>& tickets)
{
    if(tickets.size()<1) return {};
    else if(tickets.size()<2) return tickets.back();

    unordered_map<string, map<string, int>> points;
    vector<string> result;

    for(auto ticket : tickets)
    {
        points[ticket[0]][ticket[1]]++;
    }
    res.emplace_back("JFK");
    recur(points, tickets.size()+1);
    return res;
}

bool Solution::recur(unordered_map<string, map<string, int>>& points, int n)
{
    if(res.size()==n)
    {
        return true;
    }

    for(auto it = points[res.back()].begin(); it!=points[res.back()].end(); it++)
    {
        if(it->second>0)
        {
            res.emplace_back(it->first);
            it->second--;
            if(recur(points, n)) return true;
            it->second++;
            res.pop_back();
        }
    }
    return false;
}