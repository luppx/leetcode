#include <vector>
#include <queue>
using namespace std;

// //快排，然后返回前k个数
// //时间复杂度O(NlogN)，空间复杂度O(logN)
// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> res;
//         if(arr.empty()) return res;
//         int size = arr.size();

//         QuickSort(arr, 0, size-1);

//         int bound = k;
//         if(bound>size) bound = size; //如果k>arr.size()，则输出数组所有元素

//         for (int i = 0; i < bound; i++)
//         {
//             res.push_back(arr[i]);
//         }
//         return res;
//     }

// private:
//     void QuickSort(vector<int>& arr, int left, int right)
//     {
//         if (left < right)
//         {
//             int pivot_position = Partition(arr, left, right);
//             QuickSort(arr, left, pivot_position-1);
//             QuickSort(arr, pivot_position+1, right);
//         }
//     }

//     int Partition(vector<int>& arr, int left, int right)
//     {
//         int pivot = arr[left];
//         while (left<right)
//         {
//             while(left<right && arr[right]>=pivot) right--;
//             arr[left] = arr[right];
//             while(left<right && arr[left]<=pivot) left++;
//             arr[right] = arr[left];
//         }
//         arr[left] = pivot;
//         return left;
//     }
// };

// //快排优化，不需要全部完成排序，只要排完前k个数就能跳出递归了。也即当pivot=k-1时，说明前k个数已经排好序。
// //因为题目没有说明输出需要按序排列，所以只要前k个数是最小的就可以了，也即确定第k个最小数字的位置(pivot==k-1)就可以了(pivot左边的数都比他小，右边的数都比他大)
// //时间复杂度O(N)，空间复杂度O(logN)
// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> res;
//         if(arr.empty() || k==0) return res;
//         int size = arr.size();

//         QuickSort(arr, k, 0, size-1);

//         int bound = k;
//         if(bound>size) bound = size; //如果k>arr.size()，则输出数组所有元素

//         res.assign(arr.begin(), arr.begin()+bound);
//         return res;
//     }

// private:
//     void QuickSort(vector<int>& arr, int k, int left, int right)
//     {
//         if (left<right)
//         {
//             int pivot_position = Partition(arr, left, right);
//             if(pivot_position==(k-1)) return;
//             else if(pivot_position>k)
//             {
//                 QuickSort(arr, k, left, pivot_position-1);
//             }
//             else
//             {
//                 QuickSort(arr, k, pivot_position+1, right);
//             }
//         }
//     }

//     int Partition(vector<int>& arr, int left, int right)
//     {
//         int pivot = arr[left];
//         while (left<right)
//         {
//             while(left<right && arr[right]>=pivot) right--;
//             arr[left] = arr[right];
//             while(left<right && arr[left]<=pivot) left++;
//             arr[right] = arr[left];
//         }
//         arr[left] = pivot;
//         return left;
//     }
// };

//使用大根堆维护当前数组前k小的元素。如果出现比堆顶元素大的数字，则弹出堆顶元素，将该元素压入堆中。
//C++ 优先队列(priority_queue)就是用大根堆实现的。
//时间复杂度O(NlogK)，大根堆实时维护前k小的值，插入删除操作都是O(logK)复杂度，最坏情况下N个元素都要插入堆中，即O(NlogK)
//空间复杂度O(K)
class Solution
{
private:
    /* data */
public:
    Solution();
    ~Solution();
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> res;
        if(arr.empty() || k==0) return res;
        else if(k>=(int)arr.size()) return arr;

        priority_queue<int> Q;
        for (int i = 0; i < k; i++)
        {
            Q.push(arr[i]);
        }
        
        for (int i = k; i < (int)arr.size(); i++)
        {
            if(arr[i]<Q.top())
            {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        
        for (int i = 0; i < k; i++)
        {
            res.push_back(Q.top());
            Q.pop();
        }
        return res;
    }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}


int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,2};
    Solution obj;
    vector<int> result = obj.getLeastNumbers(arr, 2);
    return 0;
}
