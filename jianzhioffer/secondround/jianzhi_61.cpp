#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
	bool isStraight(vector<int>& nums);
};

//先排序再遍历，时间复杂度O(NlogN)，空间复杂度O(1)
//bool Solution::isStraight(vector<int>& nums)
//{
//	if(nums.size()!=5) return false;
//	sort(nums.begin(), nums.end());
//	
//	int count_0 = 0;
//	for(int i=0; i<nums.size()-1; i++)
//	{
//		if(nums[i]==0) count_0++;
//		else if(nums[i+1]==nums[i]) return false;
//		else if(nums[i+1]-nums[i]==1) continue;
//		else if((nums[i+1]-nums[i]-1)<=count_0) count_0 -= (nums[i+1]-nums[i]-1);
//		else return false;
//	}
//	return true;
//}

//利用set。时间复杂度O(N)(遍历数组花费O(N)时间，set查找元素只需O(1)时间)，空间复杂度O(N)(建立set消耗O(N)空间)
bool Solution::isStraight(vector<int>& nums)
{
	if(nums.size()!=5) return false;
	set<int> s;
	int min=13, max=1;
	for(auto num:nums)
	{
		if(num==0) continue;
		if(s.find(num)!=s.end()) return false; //有除0之外的重复数字，肯定无法形成顺子，直接返回
		s.insert(num);
		if(num<min) min=num;
		if(num>max) max=num;
	}
	
	if(max-min<5) return true;
	return false;
}

int main()
{
	vector<int> nums = {0,0,2,1,5};
	Solution obj;
	bool result = obj.isStraight(nums);
	return 0;
}
