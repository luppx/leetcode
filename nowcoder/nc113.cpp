#include <string>
using namespace std;

class Solution
{
public:
    string solve(string& IP);
};

string Solution::solve(string& IP)
{
    //IP地址为空或IP首字符为":"
    if(IP.empty() || IP.front()==':') return "Neither";

    bool is_ipv4 = true;
    bool is_ipv6 = true;

    string ne = "Neither";
    string ipv4 = "IPv4";
    string ipv6 = "IPv6";
    int count = 0;
    for (int i = 0; i < IP.size(); i++)
    {
        string tmp="";
        while(IP[i]!='.' && IP[i]!=':' && i<(int)IP.size())
        {
            tmp += IP[i];
            //如果分组的首字符为0
            if(IP[i]=='0' && tmp.size()==1)
            {
                is_ipv4 = false;
                //如果也不是IPV6，则直接返回
                if(i<IP.size()-1 && IP[i+1]=='0')
                {
                    is_ipv6 = false;
                    return ne;
                }
                i++;
            }
            else if(IP[i]>='0' && IP[i]<='9')
            {
                i++;
            }
            else if((IP[i]>='a' && IP[i]<='z') || (IP[i]>='A' && IP[i]<='Z'))
            {
                is_ipv4 = false;
                i++;
            }
            else
            {
                is_ipv4 = false;
                is_ipv6 = false;
                return ne;
            }

            if((!is_ipv4 && !is_ipv6) || tmp.size()>4) return ne;
        }
        count++;
        if(count>4 || stoi(tmp)>255) is_ipv4 = false;
        if(count>8 || stoi(tmp)>0xFFFF) is_ipv6 = false;
        if((!is_ipv4 && !is_ipv6)) return ne;
    }
    
    if(count!=4) is_ipv4 = false;
    if(count!=8) is_ipv6 = false;

    if(is_ipv4) return ipv4;
    else if(is_ipv6) return ipv6;
    else return ne;
}

int main()
{
    string IP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    Solution obj;
    string result = obj.solve(IP);
    return 0;
}