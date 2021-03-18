#include <iostream>
using namespace std;

class Solution
{
public:
	int add(int a, int b);
};

int Solution::add(int a, int b)
{
	if(b==0) return a;
	return add(a^b, (unsigned int)(a&b)<<1); //a^b表示非进位和(^为异或)，(a&b)<<1表示进位和；C++中数字都以补码形式存储，g++编译器下移位时补码符号位也会一起移动，但leetcode编译器不会移动符号位，会报错，所以要将其转换成无符号整数再移位
}

int main()
{
	cout<<"Hello!\nPlease enter number a and number b\n";
	int a=0, b=0;
	cin>>a>>b;
	Solution obj;
	int result = obj.add(a,b);
	cout<<"a+b="<<result<<"\n";
	return 0;
}
