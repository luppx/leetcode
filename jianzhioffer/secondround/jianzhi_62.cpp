#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int lastRemaining(int n, int m);
};

//模拟法，时间复杂度O(MN)，空间复杂度O(N)，会超时
//int Solution::lastRemaining(int n, int m)
//{
//	if(n<1 || m<1) return -1;
//	int cur=0;
//	int count_remaining=n;
//	map<int, bool> m_deleted;
//	for(int i=0; i<n; i++) m_deleted[i]=false;
//
//	while(count_remaining>1)
//	{
//		int count=0;
//		while(count<m)
//		{
//			if(m_deleted[cur]==false)  //所在数字未被删除
//			{
//				if(count==(m-1))
//				{
//					m_deleted[cur]=true;
//					count_remaining--;
//					break;
//				}
//				cur = cur==(n-1) ? 0:(cur+1);
//				count++;
//			}
//			else cur = cur==(n-1) ? 0:(cur+1);
//		}
//	}
//	for(map<int,bool>::iterator it=m_deleted.begin(); it!=m_deleted.end(); it++)
//	{
//		if(it->second==false) return it->first;
//	}
//	return -1;
//}

//此题属于约瑟夫环问题，用动态规划求解。时间复杂度O(N)，空间复杂度O(1)
int Solution::lastRemaining(int n, int m)
{
	if(n<1 || m<1) return -1;
	int tmp = 0; //dp[1]=0
	for(int i=2; i<=n; i++)
	{
		tmp = (tmp+m)%i;
	}
	return tmp;
}

int main()
{
	Solution obj;
	int result = obj.lastRemaining(5,3);
	return 0;
}
