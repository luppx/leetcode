#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);
};

int Solution::fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    int res = 0;
    unordered_map<int, int> umap;

    for (int a : nums1)
    {
        for(int b : nums2)
        {
            umap[a+b]++;
        }
    }
    
    for(int c : nums3)
    {
        for(int d : nums4)
        {
            int x = -(c+d);
            if(umap.find(x)!=umap.end())
            {
                res += umap[x];
            }
        }
    }

    return res;
}

int main()
{
    return 0;
}