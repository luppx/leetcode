class Solution
{
public:
	int sumNums(int n);
private:
	int quickmultiply(int a, int b);
};


//递归。时间复杂度O(N),空间复杂度O(N)
//int Solution::sumNums(int n)
//{
//	(n>0) && (n+=sumNums(n-1));  //不能用if、for等语句，故利用&&的短路性质。即(A&&B)，如果A已判定为false，那么结果必定为false，就不会再执行B，从而能跳出递归。同理，如果是(A||B),当A已判定为true时，便不会再执行B
//	return n;
//}

//方法二，利用快速乘方法(见此题官方题解以及0_quickmultiply)。时间复杂度O(logN)，空间复杂度O(logN)
//此题为公差为1的等差数列，求和公式=n*(n+1)/2，则只需利用快速乘方法求出n与n+1的乘积
int Solution::sumNums(int n)
{
	return quickmultiply(n, n+1)>>1; //结果要记得除以2
}

int Solution::quickmultiply(int a, int b)
{
	int ans = 0;
	bool flag = (b!=0) && (b&1) && (ans=a)>=0;
	flag = (b!=0) && (ans += quickmultiply(a<<1, b>>1))>=0;
	return ans;
}

int main()
{
	Solution obj;
	int result = obj.sumNums(5);
	return result;
}
