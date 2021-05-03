#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<string>> topKstrings(vector<string>& strings, int k);
};

// //方法一，哈希表存各字符串出现的次数，然后用vector存储哈希表的字符串和出现次数，对vector排序，最后取vector前k个
// bool compare(const vector<string>& v1, const vector<string>& v2)
// {
//     int v1_count = stoi(v1.back());
//     int v2_count = stoi(v2.back());
//     return v1_count>v2_count || (v1_count==v2_count && v1.front()<=v2.front());
// }

// vector<vector<string>> Solution::topKstrings(vector<string>& strings, int k)
// {
//     if(strings.empty() || k<1) return {};
//     else if(strings.size()<2) return {strings};

//     unordered_map<string, string> m;
//     for (int i = 0; i < strings.size(); i++)
//     {
//         if(m.find(strings[i])==m.end()) m[strings[i]] = '1';
//         else m[strings[i]] = to_string(stoi(m[strings[i]])+1);
//     }
    
//     vector<vector<string>> tmp = {};
//     for (unordered_map<string,string>::iterator it = m.begin(); it != m.end(); it++)
//     {
//         tmp.push_back({it->first, it->second});
//     }
//     sort(tmp.begin(), tmp.end(), compare);

//     if(k>=tmp.size()) return tmp;

//     vector<vector<string>> res(k,vector<string>(k));
//     copy(tmp.begin(), tmp.begin()+k, res.begin());
//     return res;
// }

//方法二，哈希表+优先队列
struct cmp
{
    bool operator()(const pair<string, int>& v1, const pair<string, int>& v2) //建小顶堆
    {
        return v1.second>v2.second || (v1.second==v2.second && v1.first<=v2.first);
    }
};


vector<vector<string>> Solution::topKstrings(vector<string>& strings, int k)
{
    if(strings.empty() || k<1) return {};
    else if(strings.size()<2) return {strings};

    unordered_map<string, int> m;
    for (int i = 0; i < strings.size(); i++)
    {
        m[strings[i]]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> q;

    for(auto p:m)
    {
        if(q.size()<k)
        {
            q.push(p);
        }
        else
        {
            if(p.second>q.top().second || (p.second==q.top().second && p.first<q.top().first))
            {
                q.pop();
                q.push(p);
            }
        }
    }

    vector<vector<string>> res(k);
    int idx = k-1;
    while (!q.empty())
    {
        res[idx--] = {q.top().first, to_string(q.top().second)};
        q.pop();
    }
    
    return res;
}

int main()
{
    vector<string> strings = {"a","b","c","b"};
    // vector<string> strings = {"mv4r6","AiA2W","8YT","NKq","8","hHGqd","gOh","2W","148i","dH6","z","Pdis"};
    int k = 2;
    Solution obj;
    vector<vector<string>> result = obj.topKstrings(strings, k);
    return 0;
}