#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people);
};

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    // if(v1[0]>v2[0]) return true;
    // else if(v1[0]==v2[0] && v1[1]<=v2[1]) return true;
    // else return false;
    return (v1[0]>v2[0]) || (v1[0]==v2[0] && v1[1]<=v2[1]);
}

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>>& people) {
    if(people.empty()) return {};

    sort(people.begin(), people.end(), cmp);

    list<vector<int>> resList;
    for(int i=0; i<people.size(); i++)
    {
        int count = people[i][1];
        auto it = resList.begin();
        while (count>0 && it!=resList.end())
        {
            count--;
            it++;
        }
        resList.insert(it, people[i]);
    }
    
    vector<vector<int>> res;
    for(auto it=resList.begin(); it!=resList.end(); it++)
    {
        res.emplace_back(*it);
    }
    return res;
}

int main()
{
    vector<vector<int>> people = {
        {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}
    };

    Solution obj;
    vector<vector<int>> result = obj.reconstructQueue(people);
    return 0;
}