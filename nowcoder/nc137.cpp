#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(string& s);

private:
    vector<string> nibolan(string& s);
};

int Solution::solve(string& s)
{
    if(s.empty()) return 0;

    vector<string> s2 = nibolan(s); //将中缀表达式转换成后缀表达式(逆波兰表示法)

    stack<int> stack_num;
    for (int i = 0; i < s2.size(); i++)
    {
        if(s2[i]=="+" || s2[i]=="-" || s2[i]=="*" || s2[i]=="/")
        {
            int b = stack_num.top();
            stack_num.pop();
            int a = stack_num.top();
            stack_num.pop();
            
            if (s2[i]=="+")
            {
                stack_num.push(a+b);
            }
            else if(s2[i]=="-")
            {
                stack_num.push(a-b);
            }
            else if(s2[i]=="*")
            {
                stack_num.push(a*b);
            }
            else
            {
                if(b!=0) stack_num.push(a/b);
            }
        }
        else
        {
            stack_num.push(stoi(s2[i]));
        }
        
    }
    return stack_num.top();
}

vector<string> Solution::nibolan(string& s)
{
    stack<char> s1;
    vector<string> tokens = {};

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            int idx = i;
            while (s[idx]>='0' && s[idx]<='9')
            {
                idx++;
            }
            tokens.push_back(s.substr(i, idx-i));
            i = idx-1;
        }
        else if(s[i]=='(') s1.push(s[i]);
        else if(s[i]==')')
        {
            while (!s1.empty())
            {
                char sign = s1.top();
                s1.pop();
                if(sign=='(') break;
                else
                {
                    string tmp(1, sign);
                    tokens.push_back(tmp);
                }
            }
        }
        else  //+、-、*
        {
            if(s1.empty()) s1.push(s[i]);
            else
            {
                if(s[i]=='*' || s[i]=='/')
                {
                    while (!s1.empty())
                    {
                        char sign = s1.top();
                        if(sign=='*' || sign=='/')
                        {
                            s1.pop();
                            string tmp(1, sign);
                            tokens.push_back(tmp);
                        }
                        else break;
                    }
                    s1.push(s[i]);
                }
                else if(s[i]=='+' || s[i]=='-')
                {
                    while (!s1.empty())
                    {
                        char sign = s1.top();
                        if(sign=='+' || sign=='-' || sign=='*' || sign=='/')
                        {
                            s1.pop();
                            string tmp(1, sign);
                            tokens.push_back(tmp);
                        }
                        else break;
                    }
                    s1.push(s[i]);
                }
            }
        } 
    }

    while (!s1.empty())
    {
        char sign = s1.top();
        s1.pop();
        string tmp(1, sign);
        tokens.push_back(tmp);
    }
    
    return tokens;
}

int main()
{
    //string s = "(1+2)*2*3";
    // string s = "3+2*3*4-1";
    string s = "((10+2)*10-(100-(10+20*10-(2*3)))*10*1*2)-2";
    Solution obj;
    int result = obj.solve(s);
    return 0;
}