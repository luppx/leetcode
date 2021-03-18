#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<int> constructArr(vector<int>& a);
};


//时间复杂度O(N^2)，空间复杂度O(N)。用一个变量存储前i-1个变量的乘积，这样内循环可以少遍历一半的次数，略微优化了时间消耗。但leetcode还是会超时
//vector<int> Solution::constructArr(vector<int>& a)
//{
//	if(a.size()<2) return a;
//	vector<int> res {};
//	int prevmultisum = 1;
//	for(int i=0; i<a.size(); i++)
//	{
//		int tmp=prevmultisum;
//		for(int j=i+1; j<a.size(); j++)
//		{
//			tmp *= a[j];
//		}
//		res.push_back(tmp);
//		prevmultisum *= a[i];
//	}
//	return res;
//}

//对方法一的优化，两次遍历数组，先计算前i-1个元素的乘积并直接存到数组中，再倒序遍历数组，计算i之后的元素的乘积(同样可用一个辅助变量存储后i个元素的乘积和，降低空间消耗)
//其实这道题就是个dp，维护两个dp数组，分别维护前i-1个元素的乘积和以及i之后元素的乘积和，这里利用辅助变量和要返回的数组，将空间消耗降到最低
//时间复杂度O(N)，空间复杂度O(N)(返回一个数组，创建该数组消耗O(N)空间)
vector<int> Solution::constructArr(vector<int>& a)
{
	if(a.size()<2) return a;
	vector<int> res(a.size(),1);
	
	for(int i=1; i<a.size(); i++)
	{
		res[i] = res[i-1]*a[i-1];
	}

	int tmp=1;
	for(int i=a.size()-2; i>=0; i--)
	{
		tmp *= a[i+1];
		res[i] *= tmp;
	}
	return res;
}

int main()
{
	cout<<"Please enter the size of vector:";
	int size = 0;
	cin>>size;
	cout<<"\nPlease enter elements(type:int):\n";
	vector<int> nums = {};
	int element;
	while(size--)
	{
		cin>>element;
		nums.push_back(element);
	}
	cout<<"Input finished\n";
	
	Solution obj;
	vector<int> result = obj.constructArr(nums);
	return 0;
}
