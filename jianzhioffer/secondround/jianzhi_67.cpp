#include <unordered_map>
#include <string>
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:

        enum State
        {   
                STATE_INITIAL,
                STATE_SIGN,
                STATE_NUMBER,
                STATE_ILLEGAL,
                STATE_END
        };  

        enum CharType
        {   
                CHAR_SIGN,
                CHAR_NUMBER,
                CHAR_ILLEGAL
        };  

        //时间复杂度O(N)，空间复杂度O(1)。这题状态比较少，判断很简单，用状态机属于简单问题复杂化了...
	//而且在ubuntu下一直编译不通过，提示unordered_map的初始化格式不对...但在leetcode和vs code上都通过了
	//google发现有人也碰到了这个问题，把g++版本升级到7之后就解决了，估计是g++版本问题，后面有时间验证一下。
	int strToInt(string str)
        {   
            unordered_map<State, unordered_map<CharType, State>> transfer=
            {
                    {STATE_INITIAL, 
                            {
                                    {CHAR_SIGN, STATE_SIGN},
                                    {CHAR_NUMBER, STATE_NUMBER},
                                    {CHAR_ILLEGAL, STATE_END}
                            }
                    },
                    {STATE_SIGN,
                            {
                                    {CHAR_SIGN, STATE_END},
                                    {CHAR_NUMBER, STATE_NUMBER},
                                    {CHAR_ILLEGAL, STATE_END}
                            }
                    },
                    {STATE_NUMBER,
                            {
                                    {CHAR_SIGN, STATE_END},
                                    {CHAR_NUMBER, STATE_NUMBER},
                                    {CHAR_ILLEGAL, STATE_END}
                            }
                    }
            };

            int i = str.find_first_not_of(' ');
            if(i==string::npos) return 0; //字符串全为空格，肯定不能转为整数
            int j = str.find_last_not_of(' ');
            str = str.substr(i, j-i+1);  //去除首尾空格，并复制

            int sign = 1;
            int res = 0;
            int boundary = INT_MAX /10;
            State st=STATE_INITIAL;
            for(int i=0; i<str.size(); i++)
            {
                    st=transfer[st][judgeCharType(str[i])];
                    if(st==STATE_END) break;
                    else
                    {
                        if(str[i]=='-') sign = -1;
                        else if(str[i]=='+') continue;
                        else
                        {
                            //判断数字是否超过最大数
                            if(res>boundary || (res==boundary && str[i]>'7'))
                                return sign==1 ? INT_MAX : INT_MIN;
                            res = res*10 + (str[i]-'0');
                        }
                    } 
            }
            return res*sign;
        }

        CharType judgeCharType(char s)
        {
            if(s=='+' || s=='-') return CHAR_SIGN;
            else if(s>='0' && s<='9') return CHAR_NUMBER;
            else return CHAR_ILLEGAL;
        }
};



int main()
{
        cout<<"Please enter a string:";
        string s;
        cin>>s;
        Solution obj;
        int result = obj.strToInt(s);
        return 0;
}

