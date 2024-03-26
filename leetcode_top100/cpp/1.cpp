#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> nums, int target);
};

vector<int> Solution::twoSum(vector<int> nums, int target)
{
	vector<int> res = {};
	if(nums.size()<1) return res;
	
	unordered_map<int, int> map;
	for(int i=0; i<nums.size(); i++)
	{
		if(map.find(target-nums[i])!=map.end())
		{
			res.push_back(map[target-nums[i]]);
			res.push_back(i);
			break;
		}
		map[nums[i]]=i;
	}
	
	return res;
}

int main()
{
	vector<int> nums={2, 7, 11, 15};
	Solution obj;
	vector<int> result = obj.twoSum(nums, 9);
	return 0;
}


