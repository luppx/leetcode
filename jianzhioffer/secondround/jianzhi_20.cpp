#include <string>
#include <unordered_map>
using namespace std;

// //知道要用有限状态自动机，但对状态的枚举不完善，以下为根据题解完善的代码
// //时间复杂度O(N)(遍历一次字符串)，空间复杂度O(1)(建立一个固定大小的状态转移表)
// class Solution {
// public:
//     //状态：
//     //1.起始的空格
//     //2.符号位(+、-)
//     //3.整数部分，即小数点前的整数部分
//     //4.左侧有数字的小数点
//     //5.右侧有数字左侧没有的小数点(4、5表示小数点至少一侧有数字，而不是只有一个小数点)
//     //6.小数部分
//     //7.幂符号(e、E)
//     //8.幂符号后的符号位
//     //9.幂符号符号位后的整数
//     //10.末尾的空格
//     enum State
//     {
//         STATE_INITIAL,
//         STATE_SIGN,
//         STATE_INTEGER,
//         STATE_POINT,
//         STATE_POINT_WITHOUT_INTEGER,
//         STATE_FRACTION,
//         STATE_EXP,
//         STATE_EXP_SIGN,
//         STATE_EXP_NUMBER,
//         STATE_END
//     };

//     enum CharType
//     {
//         CHAR_SPACE, //空格
//         CHAR_SIGN, //符号位
//         CHAR_NUMBER,  //数字
//         CHAR_POINT,  //小数点
//         CHAR_EXP,  //幂符号
//         CHAR_ILLEGAL //其他非法符号
//     };

//     CharType judgeCharType(char ch)
//     {
//         if(ch==' ') return CHAR_SPACE;
//         else if(ch=='+' || ch=='-') return CHAR_SIGN;
//         else if(ch>='0' && ch<='9') return CHAR_NUMBER;
//         else if(ch=='.') return CHAR_POINT;
//         else if(ch=='e' || ch=='E') return CHAR_EXP;
//         else return CHAR_ILLEGAL;
//     }

//     bool isNumber(string s) {
//         if(s.empty()) return false;
//         unordered_map<State, unordered_map<CharType, State>> transfer
//         {
//             {STATE_INITIAL, {
//                 {CHAR_SPACE, STATE_INITIAL},
//                 {CHAR_SIGN, STATE_SIGN},
//                 {CHAR_NUMBER, STATE_INTEGER},
//                 {CHAR_POINT, STATE_POINT_WITHOUT_INTEGER}
//                 }
//             },
//             {STATE_SIGN, {
//                 {CHAR_NUMBER, STATE_INTEGER},
//                 {CHAR_POINT, STATE_POINT_WITHOUT_INTEGER},
//                 }   
//             },
//             {STATE_INTEGER, {
//                 {CHAR_NUMBER, STATE_INTEGER},
//                 {CHAR_POINT, STATE_POINT},
//                 {CHAR_EXP, STATE_EXP},
//                 {CHAR_SPACE, STATE_END}
//                 }
//             },
//             {STATE_POINT, {
//                 {CHAR_NUMBER, STATE_FRACTION},
//                 {CHAR_EXP, STATE_EXP},
//                 {CHAR_SPACE, STATE_END}
//                 }
//             },
//             {STATE_POINT_WITHOUT_INTEGER, {
//                 {CHAR_NUMBER, STATE_FRACTION}
//                 }
//             },
//             {STATE_FRACTION, {
//                 {CHAR_NUMBER, STATE_FRACTION},
//                 {CHAR_EXP, STATE_EXP},
//                 {CHAR_SPACE, STATE_END}
//                 }
//             },
//             {STATE_EXP, {
//                 {CHAR_SIGN, STATE_EXP_SIGN},
//                 {CHAR_NUMBER, STATE_EXP_NUMBER}
//                 }
//             },
//             {STATE_EXP_SIGN, {
//                 {CHAR_NUMBER, STATE_EXP_NUMBER}
//                 }
//             },
//             {STATE_EXP_NUMBER, {
//                 {CHAR_NUMBER, STATE_EXP_NUMBER},
//                 {CHAR_SPACE, STATE_END}
//                 }
//             },
//             {STATE_END, {
//                 {CHAR_SPACE, STATE_END}
//                 }
//             }
//         };

//         int len = s.size();
//         State st = STATE_INITIAL;
//         for (int i = 0; i < len; i++)
//         {
//             CharType type = judgeCharType(s[i]);
//             if(transfer[st].find(type) == transfer[st].end()) return false;
//             else st = transfer[st][type];
//         }

//         return st==STATE_INTEGER || st==STATE_POINT || st==STATE_FRACTION || st==STATE_EXP_NUMBER || st==STATE_END;
//     }
// };


//数字可分为A.B[e||E]C或.B[e||E]C这两种格式。其中只有A、C部分能有符号位且符号位只能在第一位出现。
//根据幂符号e(E)可将数字分为底数和指数两部分，分别进行判断
class Solution
{
public:
    bool isNumber(string s){
        if(s.empty()) return false;
        //去除首尾空格
        int i = s.find_first_not_of(' ');
        if(i==string::npos) return false;
        int j = s.find_last_not_of(' ');
        string s_sub = s.substr(i, j-i+1);
        if(s_sub.empty()) return false;

        //确定e(E)的位置
        int e_pos = -1;
        for (int i = 0; i < s_sub.size(); i++)
        {
            if (s_sub[i]=='e' || s_sub[i]=='E')
            {
                e_pos=i;
                break;
            }
        }

        if(e_pos==-1)  //未出现e，只用判断底数部分
            return judgeBase(s_sub);
        else
        {
            string base = s_sub.substr(0,e_pos);
            string exponent = s_sub.substr(e_pos+1);
            if(base.empty() || exponent.empty()) return false; //幂符号在首位或末位的情况，都不算数字
            
            return judgeBase(base) && judgeExponent(exponent);
        }

    }

    bool judgeBase(string& s)  //判断底数部分
    {
        bool point = false;
        bool res = false;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='+' || s[i]=='-')
            { 
                if(i!=0) return false; //符号位不在第一位
                else continue;
            }
            else if(s[i]=='.')
            {
                if(point) return false;  //出现多个小数点
                point = true;
            } //如果底数部分只有一个小数点的话，由于未改变res的值，所以返回的是false，正确判断了该情况
            else if(s[i]<'0' || s[i]>'9') 
                return false; //出现除“+、-、小数点、数字0-9”之外的其他符号(因为是判断底数部分，所以不用考虑幂符号)
            else res=true;
        }
    
        return res;
    }

    bool judgeExponent(string& s)  //判断指数部分
    {
        bool res = false;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='+' || s[i]=='-') 
                if(i!=0) return false; //符号位不在第一位
                else continue;
            else if(s[i]<'0' || s[i]>'9') 
                return false; //出现除“+、-、数字0-9”之外的其他符号(因为是判断指数部分，所以不用考虑幂符号，且不能出现小数点)
            else res=true;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string strs=" .1 ";
    Solution obj;
    bool result = obj.isNumber(strs); 
    return 0;
}
