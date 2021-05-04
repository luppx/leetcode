#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n);

private:
    void dfs(string& parenthesis, int leftCount, int rightCount);
    vector<string> res;
    int maxleftCount;
    int maxtotalCount;
};

vector<string> Solution::generateParenthesis(int n)
{
    if(n<1) return {};
    else if(n<2) return {"()"};

    res = {};
    maxleftCount = n;
    maxtotalCount = n*2;
    string str = "";
    dfs(str, 0, 0);
    return res;
}

void Solution::dfs(string& parenthesis, int leftCount, int rightCount)
{
    if(leftCount+rightCount==maxtotalCount)
    {
        res.push_back(parenthesis);
        return;
    }

    if(leftCount<maxleftCount)
    {
        parenthesis.push_back('(');
        dfs(parenthesis, leftCount+1, rightCount);
        parenthesis.pop_back();
    }
    if(leftCount>rightCount)
    {
        parenthesis.push_back(')');
        dfs(parenthesis, leftCount, rightCount+1);
        parenthesis.pop_back();
    }

    return;
}

int main()
{
    int n = 3;
    Solution obj;
    vector<string> result = obj.generateParenthesis(n);
    return 0;
}