#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens);
};

int Solution::evalRPN(vector<string>& tokens)
{
    if(tokens.empty()) return 0;
    stack<int> st = {};
    
    for(auto str : tokens)
    {
        if(str=="+" || str=="-" || str=="*" || str=="/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(str=="+")
            {
                st.push(a + b);
            }
            else if(str=="-")
            {
                st.push(a - b);
            }
            else if(str=="*")
            {
                st.push(a * b);
            }
            else if(str=="/")
            {
                st.push(a / b);
            }
        }
        else
        {
            st.push(stoi(str));
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"2","1","+","3","*"};
    Solution obj;
    int result = obj.evalRPN(tokens);
    cout<<result<<endl;
    return 0;
}