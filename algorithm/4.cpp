#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

//时间复杂度O(max(M,N))，空间复杂度O(1)
// double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
// {
//     int m = nums1.size();
//     int n = nums2.size();
//     if(m==0 && n==0) return 0;

//     int median_idx = (m+n)/2;

//     int cur_idx = 0, i = 0, j = 0;
//     int cur_val = 0;
//     while (i<m && j<n && cur_idx<median_idx)
//     {
//         if(nums1[i]<=nums2[j])
//         {
//             cur_val = nums1[i];
//             i++;
//         }
//         else
//         {
//             cur_val = nums2[j];
//             j++;
//         }
//         cur_idx++;
//     }

//     while (i<m && cur_idx<median_idx)
//     {
//         cur_val = nums1[i++];
//         cur_idx++;
//     }
//     while (j<n && cur_idx<median_idx)
//     {
//         cur_val = nums2[j++];
//         cur_idx++;
//     }

//     int median_idx_val = 0;
//     if(i<m && j<n) median_idx_val = min(nums1[i], nums2[j]);
//     else if(i<m) median_idx_val = nums1[i];
//     else median_idx_val = nums2[j];

//     if((m+n)%2==0) return ((double)(cur_val+median_idx_val)) / 2;
//     else return (double)median_idx_val;
// }

//方法二，用二分查找，时间复杂度O(log(min(M,N)))，空间复杂度O(1)
//Reference：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    if(m==0 && n==0) return 0;
    else if(m==0) return n%2 ? nums2[n/2] : (double)(nums2[n/2-1]+nums2[n/2])/2;
    else if(n==0) return m%2 ? nums1[m/2] : (double)(nums1[m/2-1]+nums1[m/2])/2;

    if(m>n) return findMedianSortedArrays(nums2, nums1);

    int mid_idx = (m+n+1)>>1;
    int low=0, high=m, mid_nums1=0, mid_nums2=0;

    while (low<=high)
    {
        mid_nums1 = low + ((high-low)>>1);
        mid_nums2 = mid_idx - mid_nums1;

        if(mid_nums1>0 && nums1[mid_nums1-1]>nums2[mid_nums2])
        {
            high = mid_nums1-1;
        }
        else if(mid_nums2>0 && mid_nums1<m && nums2[mid_nums2-1]>nums1[mid_nums1])
        {
            low = mid_nums1+1;
        }
        else break;
    }
    

    int mid_left=0, mid_right=0;

    if(mid_nums1==0 && mid_nums2>0) mid_left = nums2[mid_nums2-1];
    else if(mid_nums2==0 && mid_nums1>0) mid_left = nums1[mid_nums1-1];
    else mid_left = max(nums1[mid_nums1-1], nums2[mid_nums2-1]);
    if((m+n)%2) return (double)mid_left;

    if(mid_nums1==m) mid_right = nums2[mid_nums2];
    else if(mid_nums2==n) mid_right = nums1[mid_nums1];
    else mid_right = min(nums1[mid_nums1], nums2[mid_nums2]);
    
    return (double)(mid_left+mid_right)/2;
}

int main()
{
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3,4};
    Solution obj;
    cout<<"Median value: "<<obj.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}

