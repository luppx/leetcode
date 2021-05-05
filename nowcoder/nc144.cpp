#include <vector>
using namespace std;

class Solution
{
public:
    long long subsequence(int n, vector<int>& nums);
};

long long Solution::subsequence(int n, vector<int>& nums)
{
    if(nums.empty()) return 0;
    else if(n<2) return max(0, nums[0]);
    else if(n<3) return max(0, max(nums[0], nums[1]));

    long long pprev = 0, prev = 0, cur = 0;;
    for (int i = 0; i < n; i++)
    {
        cur = max(max((long long)nums[i], max(pprev, pprev+nums[i])), prev);
        pprev = prev;
        prev = cur;
    }
    return cur;
}

int main()
{
    vector<int> nums = {4,2,3,5};
    Solution obj;
    long long result = obj.subsequence(nums.size(), nums);
    return 0;
}