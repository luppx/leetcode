#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<double> dicesProbability(int n);
};	


//动态规划，时间复杂度O(N^2)，空间复杂度O(N^2)
//vector<double> Solution::dicesProbability(int n)
//{
//	if(n<1) return vector<double>{};
//	vector<double> res {};
//	vector<vector<int>> dp(n+1, vector<int>(6*n+1,0));
//	for(int i=1; i<=6; i++)
//	{
//		dp[1][i]=1;
//	}
//
//	for(int i=2; i<=n; i++)
//	{
//		for(int j=i; j<=6*i; j++)
//		{
//			for(int k=1; k<=6; k++)
//			{
//				if(j-k>0)
//				{
//					dp[i][j] += dp[i-1][j-k];
//				}
//				else break;
//			}
//		}
//	}
//	
//	double count = pow(6.0, n);
//	for(int i=n; i<=6*n; i++)
//	{
//		res.push_back(dp[n][i]/count);
//	}
//	return res;
//}

//优化空间的动态规划。不建二维数组dp，dp只用一维，另建一个辅助数组存储n-1个骰子各点数出现的次数
//时间复杂度O(N^2)，空间复杂度O(N)
vector<double> Solution::dicesProbability(int n)
{
	if(n<1) return vector<double>{};
	vector<double> res {};
	vector<int> tmp(6*n+1,0);
	
	for(int i=1; i<=6; i++) tmp[i] = 1;
	
	for(int i=2; i<=n; i++)
	{
		vector<int> dp(6*i+1,0);
		for(int j=i; j<=6*i; j++)
		{
			for(int k=1; k<=6; k++)
			{
				if(j-k>0) dp[j] += tmp[j-k];
				else break; 
			}
		}

		copy(dp.begin(), dp.end(), tmp.begin());
	}

	double counts = pow(6, n);
	for(int i=n; i<=6*n; i++)
	{
		res.push_back(tmp[i]/counts);
	}
	return res;
}

int main()
{
	Solution obj;
	vector<double> result = obj.dicesProbability(2);
	return 0;
}
