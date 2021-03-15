#include <string>
using namespace std;

class Solution
{
public:
	string reverseLeftWords(string s, int n);
};

//时间复杂度O(N)，空间复杂度O(N)(建立辅助变量存储要旋转的子字符串)
//string Solution::reverseLeftWords(string s, int n)
//{
//	if(s.empty() || n>=s.size()) return s;
//	string tmp = s.substr(0,n);
//	s.erase(0,n);
//	return s+tmp;
//}

//用substr获取两个字字符串然后拼接。时间复杂度O(N)，空间复杂度O(N)，效率最低
//string Solution::reverseLeftWords(string s, int n)
//{
//	if(s.empty() || n>=s.size()) return s;
//	return s.substr(n)+s.substr(0,n);
//}

//三次反转。时间复杂度O(N)，空间复杂度O(1)
string Solution::reverseLeftWords(string s, int n)
{
	if(s.empty() || n>=s.size()) return s;
	reverse(s.begin(),s.begin()+n); //反转前n个字符
	reverse(s.begin()+n,s.end());  //反转剩余字符
	reverse(s.begin(),s.end());  //反转整个字符串
	return s;
}



int main()
{
	string s="abcdefg";
	Solution obj;
	string result = obj.reverseLeftWords(s,3);
	return 0; 
}
