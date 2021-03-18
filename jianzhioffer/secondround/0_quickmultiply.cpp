int quickMultiply(int a, int b) //俄罗斯农民乘法。计算两数相乘之和，常用于两数相乘取模的场景，以避免数值上溢
{
	int ans=0;
	for( ; b; b>>=1)
	{
		if(b&1) ans += a;
		a<<=1;
	}
	return ans;
}

int main()
{
	int a=10, b=5;
	int result = quickMultiply(a,b);
	return 0;
}
