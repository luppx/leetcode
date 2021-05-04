#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    double maxProduct(vector<double>& nums);
};

double Solution::maxProduct(vector<double>& nums)
{
    if(nums.empty()) return 0;
    else if(nums.size()<2) return nums.front();

    int n=nums.size();
    double cur_max = nums[0], cur_min = nums[0];
    double max_product = nums[0];

    for (int i = 1; i < n; i++)
    {
        double tmp_curmax = cur_max;
        cur_max = max(nums[i], max(cur_max*nums[i], cur_min*nums[i]));
        cur_min = min(nums[i], min(tmp_curmax*nums[i], cur_min*nums[i]));
        max_product = max(max_product, cur_max);
    }
    return max_product;
}

int main()
{
    vector<double> nums = {0.1,0.0,3.0,-2.0,0.9,-1.3,5.0,-4.4};
    Solution obj;
    int result = obj.maxProduct(nums);
    return 0;
}