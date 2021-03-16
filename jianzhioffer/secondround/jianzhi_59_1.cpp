#include <vector>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k);

};

//时间复杂度O(N*K)(若前一个窗口的最大值被删除了，则需要重新遍历窗口求最大值，消耗O(K))，空间复杂度O(1)
//vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
//{
//	if(nums.empty()) return vector<int>{};
//	vector<int> res = {};
//	int left=0, right=min(k,(int)nums.size()); //滑动窗口是左闭右开区间
//	
//	int prev_max = INT_MIN;
//	int max_idx = -1;
//
//	while(right<=nums.size())
//	{
//		if(max_idx>=left)
//		{
//			if(nums[right-1]>=prev_max)
//			{
//				prev_max = nums[right-1];
//				max_idx = right-1;
//			}
//			res.push_back(prev_max);
//		}
//		else
//		{
//			prev_max = nums[left];
//			max_idx =left;
//			for(int i=left+1; i<right; i++)
//			{
//				if(nums[i]>prev_max)
//				{
//					prev_max = nums[i];
//					max_idx = i;
//				}
//			}
//			res.push_back(prev_max);
//		}
//		left++;
//		right++;
//	}
//	return res;
//}

//使用双端队列，让队列为递减队列，存储当前窗口中的最大值及小于最大值的值，且让最大值位于队首，这样每次寻找最大值时只要O(1)时间
//时间复杂度O(N)，空间复杂度O(N)
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
{
	if(nums.empty()) return vector<int>{};
	vector<int> res = {};
	deque<int> dq = {};
	int left=1, right=min(k,(int)nums.size()); //滑动窗口是左闭右开区间
	
	//初始化，先解决第一个区间
	for(int i=0; i<right; i++)
	{
		while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
		dq.push_back(nums[i]);
	}
	res.push_back(dq.front());
	right++;

	while(right<=nums.size())
	{
		if(nums[left-1]==dq.front()) dq.pop_front();
		while(!dq.empty() && dq.back()<nums[right-1]) dq.pop_back();
		dq.push_back(nums[right-1]);
		res.push_back(dq.front());
		left++;
		right++;
	}
	
	return res;
}

int main()
{
	vector<int> nums {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};
	Solution obj;
	vector<int> result = obj.maxSlidingWindow(nums, 7);
	return 0;
}
