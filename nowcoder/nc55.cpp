#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        else if(strs.size()<2) return strs.back();
        
        string res = "";
        for(int i=0; i<strs[0].size(); i++)
        {
            res += strs[0][i];
            for(int j=0; j<strs.size(); j++)
            {
                if(i>=strs[j].size() || strs[j][i]!=res.back())
                {
                    res.pop_back();
                    return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    string strs;
    
}