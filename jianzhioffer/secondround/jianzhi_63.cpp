#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices);
};

//优化的动态规划。时间复杂度O(N)，空间复杂度O(1)
int Solution::maxProfit(vector<int>& prices)
{
	if(prices.size()<2) return 0;
	int maxprofit = 0;
	int min_cost = 1e9;
	for(auto price:prices)
	{
		maxprofit = max(maxprofit, price-min_cost);
		min_cost = min(min_cost, price);
	}
	return maxprofit;
}

int main()
{
	vector<int> prices = {7,6,5,4,3,2,1};
	Solution obj;
	int result = obj.maxProfit(prices);
	return 0;
}
