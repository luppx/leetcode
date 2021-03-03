#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//求全排列，用回溯法。时间复杂度O(N!)，
//空间复杂度O(N^2)(递归深度为N，累计使用栈空间大小O(N)，每次递归都会新建一个辅助set，辅助set累计存储的字母最多为N+(N-1)+...+1=N*(N+1)/2，即占用O(N^2)的空间复杂度)
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        if(s.empty()) return res;
        dfs(res, s, 0);
        return res;
    }

    void dfs(vector<string>& res, string& s, int depth)
    {
        if(depth>s.size()-1)
        {
            res.push_back(s);
            return;
        }

        unordered_set<char> used;
        for (int i = depth; i < s.size(); i++)
        {
            if(used.find(s[i])!=used.end()) //已经遍历过了这个字符
            {
                continue;
            }
            used.insert(s[i]);
            swap(s[depth], s[i]);
            dfs(res, s, depth+1);
            swap(s[i], s[depth]);
        }
    }
};

int main(int argc, char const *argv[])
{
    string s = "abb";
    Solution obj;
    vector<string> result = obj.permutation(s);
    return 0;
}
