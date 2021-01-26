# include <string>
using namespace std;


//方法一：遍历字符串，并用一个string变量存储结果。时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto ch: s)
        {
            if (ch == ' ')
            {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else
            {
                res.push_back(ch);
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    string s = "We are happy.";
    Solution obj;
    string result = obj.replaceSpace(s);
    return 0;
}

