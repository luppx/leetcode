#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
	string reverseWords(string s);
};

////遍历。时间复杂度O(N)，空间复杂度O(N)(创建辅助数组存储各个单词，占用O(N)空间)
//string Solution::reverseWords(string s)
//{
//	if(s.empty()) return "";
//	vector<string> words{};
//	string res = "";
//	for(int i=0; i<s.size(); i++)
//	{
//		if(s[i]==' ') continue;
//		
//		string tmp;
//		while(i<s.size() && s[i]!=' ')
//		{
//			tmp += s[i];
//			i++;
//		}
//		words.push_back(tmp);
//	}
//	
//	for(int i=words.size()-1; i>=0; i--)
//	{
//		res += words[i];
//		if(i>0) res += " ";
//	}
//	return res;
//}


////双指针。时间复杂度O(N)，空间复杂度O(N)(创建res变量，占用O(N)空间)
//string Solution::reverseWords(string s)
//{
//	if(s.empty()) return "";
//	string res = "";
//	int size=s.size();
//	int left=size-1, right=size-1;
//	
//	while(left>=0 && right>=0)
//	{
//		while(right>=0 && s[right]==' ') right--;
//		if(right<0) break;
//		
//		left=right;
//		string tmp="";
//		while(left>=0 && s[left]!=' ')
//		{
//			tmp += s[left];
//			left--;
//		}
//		reverse(tmp.begin(), tmp.end());
//		res += tmp;
//		res += " ";
//		if(left<0) break;
//		right=left;
//	}
//	if(!res.empty()) res.pop_back();  //先判断res内有没有单词，如果有则删除最后一个单词后多余的那个空格，如果没有表明s全为空格组成
//	return res;
//}

//双指针+原地反转。时间复杂度O(N)，空间复杂度O(1)
string Solution::reverseWords(string s)
{
	if(s.empty()) return "";
	
	int left=0;
	while(left<s.size() && s[left]==' ') left++;  //删除开头的空格
	s.erase(0, left);
	if(s.empty()) return "";
	
	int right = s.size()-1;
	while(right>=0 && s[right]==' ') right--;  //删除尾部的空格
	s.erase(right+1, s.size()-right-1);
	
	reverse(s.begin(), s.end());  //反转字符串
	left=0;
	right=0;
	while(left<s.size() && right<s.size())
	{
		while(right<s.size() && s[right]!=' ') right++;
		reverse(s.begin()+left, s.begin()+right);
		if(right==s.size()) break;
		
		left=right;
		while(s[right]==' ') right++;
		left++;
		s.erase(left, right-left); //删除单词之间多于1个的空格
		right=left;
	}
	
	return s;
}

int main()
{
	string s = "  a good   example   ";
	Solution obj;
	string result = obj.reverseWords(s);
	return 0;
}
