#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int atoi(const char* str);
};

int Solution::atoi(const char* str)
{
    if(strlen(str)==0) return 0;  //字符串为空
    int size=strlen(str);
    int cur = 0;
    while (cur<size && str[cur]==' ') cur++;

    if(cur>=size) return 0; //字符串全为空格
    
    int flag = 1;
    if(str[cur]=='+') cur++;
    else if(str[cur]=='-')
    {
        flag = -1;
        cur++;
    }
    else if(str[cur]<'0' || str[cur]>'9') return 0;  //去除空格后的首字符不为+、-、0-9，则返回0

    int res = 0;
    while (cur<size)
    {
        if(str[cur]>='0' && str[cur]<='9')
        {
            if(res>INT_MAX/10 || (res==(INT_MAX/10) && str[cur]>(INT_MAX%10)))  //判断是否上溢或下溢
            {
                if(flag==1) return INT_MAX;
                else return INT_MIN;
            }
            res = res*10 + str[cur] - '0';
            cur++;
        }
        else break;
    }
    
    return flag*res;
}

//C风格
// int Solution::atoi(const char* str)
// {
//     const char* cur = str;
//     while (*cur==' ')
//     {
//         cur++;
//     }

//     int flag = 1;
//     if(*cur=='+') cur++;
//     else if(*cur=='-')
//     {
//         flag = -1;
//         cur++;
//     }
//     else if(*cur<'0' || *cur>'9') return 0;

//     int res = 0;
//     while (*cur!='\0')
//     {
//         if(*cur>'0' && *cur<'9')
//         {
//             if(res>INT_MAX/10 || (res==(INT_MAX/10) && *cur>'7'))  //判断是否上溢或下溢
//             {
//                 if(flag==1) return INT_MAX;
//                 else return INT_MIN;
//             }
//             res = res*10 + *cur - '0';
//             cur++;
//         }
//         else break;
//     }
    
//     return flag*res;
// }


int main()
{
    char str[] = "-1234";

    Solution obj;
    int result = obj.atoi(str);
    return 0;
}