#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//方法一：辅助栈。时间复杂度O(N)，空间复杂度O(N)
// class Solution
// {
// public:
//     vector<int> getMinStack(vector<vector<int>>& op);

// private:
//     void push(int val);
//     void pop();
//     int getmin();
//     stack<int> s1;
//     stack<int> s2;
// };

// vector<int> Solution::getMinStack(vector<vector<int>>& op)
// {
//     if(op.empty()) return {};
//     s1 = {};
//     s2 = {};
//     vector<int> res = {};
//     for (int i = 0; i < op.size(); i++)
//     {
//         if(op[i][0]==1) push(op[i][1]);
//         else if(op[i][0]==2) pop();
//         else res.push_back(getmin());     
//     }
//     return res;
// }

// void Solution::push(int val)
// {
//     s1.push(val);

//     if(s2.empty() || s2.top()>=val)
//     {
//         s2.push(val);
//     }
    
// }

// void Solution::pop()
// {
//     if(s1.top()==s2.top()) s2.pop();
//     s1.pop();
// }

// int Solution::getmin()
// {
//     if(s2.empty()) return -1;
//     return s2.top();
// }

//方法二，栈内存储元素与最小值的差值。时间复杂度O(N)，空间复杂度O(1)
class Solution
{
public:
    vector<int> getMinStack(vector<vector<int>>& op);

private:
    void push(int val);
    void pop();
    int getmin();
    stack<int> s;
    int mi;
};

vector<int> Solution::getMinStack(vector<vector<int>>& op)
{
    if(op.empty()) return {};
    vector<int> res = {};
    mi = 1000001;
    for (int i = 0; i < op.size(); i++)
    {
        if(op[i][0]==1) push(op[i][1]);
        else if(op[i][0]==2) pop();
        else res.push_back(getmin());     
    }
    return res;
}

void Solution::push(int val)
{
    if(s.empty())
    {
        s.push(val);
        mi = val;
    }
    else
    {
        s.push(val-mi);  //栈不为空，则先入栈元素与当前最小值的差值，再更新最小值，这样根据前一个元素和差值就能计算出后面的最小值了
        mi = min(mi, val);
    }

}

void Solution::pop()
{
    if(s.empty()) return;
    if(s.top()>0)  //栈顶元素大于0，说明栈顶元素不是最小值，或者栈内只有一个元素，该元素即为最小值，都可直接pop
    {
        s.pop();
    }
    else
    {
        mi -= s.top();
        s.pop();
    }
}

int Solution::getmin()
{
    if(s.empty()) return -1;
    return mi;
}

int main()
{
    vector<vector<int>> op = {{1,3},{1,2},{1,1},{3},{2},{3}};
    Solution obj;
    obj.getMinStack(op);
    return 0;
}