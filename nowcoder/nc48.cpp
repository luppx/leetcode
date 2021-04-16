#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int search(int* A, int n, int target);
    
private:
    int binarySearch(int* A, int target, int left, int right);
};

int Solution::search(int* A, int n, int target)
{
    if(n<1) return -1;
    else if(n==1) return target==A[0] ? 0:-1;

    int left=0, right=n-1;
    while (left<=right)  //先找到旋转点，即数组最大值(A[right])和最小值(A[left])的下标
    {
        int mid = left + (right-left)/2;
        if(A[mid]==target) return mid;
        else if(A[mid]>=A[0]) left = mid+1;
        else right = mid-1;
    }
    
    if(target>=A[0]) return binarySearch(A, target, 0, right);
    else return binarySearch(A, target, left, n-1);
}

int Solution::binarySearch(int* A, int target, int left, int right)
{
    while (left<=right)
    {
        int mid = left + (right-left)/2;
        if(A[mid]==target) return mid;
        else if(A[mid]<target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}
