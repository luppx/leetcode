#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string& str);
};

int Solution::FirstNotRepeatingChar(string& str)
{
    if(str.empty()) return -1;
    else if(str.size()==1) return 0;

    unordered_map<char, bool> m;
    vector<int> indexs = {};
    for (int i = 0; i < str.size(); i++)
    {
        if(m.find(str[i])==m.end())
        {
            indexs.push_back(i);
            m[str[i]]=true;
        }
        else m[str[i]]=false;
    }

    for (int i = 0; i < indexs.size(); i++)
    {
        if(m[str[indexs[i]]]==true) return indexs[i];
    }

    return -1;
}

int main()
{
    string str = "google";
    Solution obj;
    int result = obj.FirstNotRepeatingChar(str);
    return 0;
}