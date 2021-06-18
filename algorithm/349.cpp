#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
};

// vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2)
// {
//     if(nums1.empty() || nums2.empty()) return {};

//     unordered_map<int, bool> intersect;
//     vector<int> res = {};
//     for (int i = 0; i < nums1.size(); i++)
//     {
//         intersect[nums1[i]] = false;
//     }

//     for (int i = 0; i < nums2.size(); i++)
//     {
//         if (intersect.find(nums2[i])!=intersect.end())
//         {
//             intersect[nums2[i]]=true;
//         }
//     }
    
//     for (auto iter = intersect.begin(); iter != intersect.end(); iter++)
//     {
//         if (iter->second==true)
//         {
//             res.push_back(iter->first);
//         }
//     }
//     return res;
// }

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.empty() || nums2.empty()) return {};

    unordered_set<int> intersect;
    unordered_set<int> set1(nums1.begin(), nums1.end());

    for (int i = 0; i < nums2.size(); i++)
    {
        if (set1.find(nums2[i])!=set1.end())
        {
            intersect.insert(nums2[i]);
        }
    }

    return vector<int>(intersect.begin(), intersect.end());
}


int main()
{
    vector<int> nums1 = {1,2,2,3,4};
    vector<int> nums2 = {2,4,2,2,4,5,6};
    Solution obj;
    vector<int> result = obj.intersection(nums1, nums2);
    return 0;
}