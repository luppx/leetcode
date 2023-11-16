#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	if(nums.size()<2) return {};

	unordered_map<int, int> m;
	
	for(int i=0; i<nums.size(); i++)
	{
		if(m.find(nums[i])!=m.end()) //找到相加=target的两个元素
		{
			return {m[nums[i]], i};
		}
		else m[target-nums[i]] = i;
	}
	return {};
}

int main()
{
	vector<int> nums = {2,11,7,15};
	int target = 9;
	Solution obj;
	vector<int> result = obj.twoSum(nums, target);
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}
