#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums);
};


//虽然有两个while，但时间复杂度是O(N)而不是O(N^2)
//因为每个元素都只涉及进一次窗口，出一次窗口，每个元素被遍历两次，时间复杂度是O(2*N)=O(N)
int Solution::minSubArrayLen(int target, vector<int>& nums)
{
    int n = nums.size();
    if(n==0) return 0;
    
    int ret = 0, len = 0;
    int sum = 0;
    int left=0, right=1;
    while (right<=n)
    {
        sum += nums[right-1];
        len++;

        while(sum>=target)
        {
            if(ret==0) ret = len;
            else ret = min(ret, len);
            sum -= nums[left];
            left++;
            len--;
        }
        right++;
    }
    return ret;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution obj;
    int result = obj.minSubArrayLen(target, nums);
    cout<<result<<endl;
    return 0;
}