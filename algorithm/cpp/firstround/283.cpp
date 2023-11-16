#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums);
};

// void Solution::moveZeroes(vector<int>& nums)
// {
//     int n = nums.size();
//     if(n<2) return;

//     int slowIndex = 0;
//     for (int fastIndex = 0; fastIndex < n; fastIndex++)
//     {
//         if(nums[fastIndex]!=0)
//         {
//             nums[slowIndex] = nums[fastIndex];
//             slowIndex++;
//         }
//     }
//     for (int i = slowIndex; i < n; i++)
//     {
//         nums[i] = 0;
//     }
//     return ;
// }

void Solution::moveZeroes(vector<int>& nums)
{
    int n = nums.size();
    if(n<2) return;

    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < n; fastIndex++)
    {
        if(nums[fastIndex]!=0)
        {
            swap(nums[slowIndex], nums[fastIndex]);
            slowIndex++;
        }
    }
    return ;
}

int main()
{
    vector<int> nums = {0,1,0,2,0,0,3,12,0};
    Solution obj;
    obj.moveZeroes(nums);
    for (int i = 0; i < nums.size()-1; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<nums.back()<<endl;
    return 0;
}