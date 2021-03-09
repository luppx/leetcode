#include <vector>
#include <queue>
using namespace std;

// //方法一，每次插入元素先快排把中间两个数排好序。
// //时间复杂度O(NlogN)，空间复杂度O(N)
// //leetcode超时
// class MedianFinder
// {
// private:
//     /* data */
// public:
//     MedianFinder(/* args */);
//     ~MedianFinder();
//     void addNum(int);
//     double findMedian();

// private:
//     void QuickSort(int&, int, int);
//     int Partition(int, int);
//     vector<int> nums;
// };

// MedianFinder::MedianFinder(/* args */)
// {
// }

// MedianFinder::~MedianFinder()
// {
// }

// void MedianFinder::addNum(int num)
// {
//     if(nums.empty()) nums.push_back(num);
//     else //每次插入后都重排最中间的数
//     {
//         nums.push_back(num);
//         int size = (int)nums.size();
//         int median_idx = size/2;
//         if(size % 2) //奇数个元素，则中位数为最中间的数
//         {
//             QuickSort(median_idx, 0, size-1);
//         }
//         else  //偶数个元素，中位数为最中间两个数，故需要快排确定最中间两个数的位置
//         {
//             int prev_median_idx = median_idx - 1;
//             QuickSort(median_idx, 0, size-1);
//             QuickSort(prev_median_idx, 0, size-1);
//         }
//     }
// }

// double MedianFinder::findMedian()
// {
//     if(nums.empty()) return 0;

//     int size = (int)nums.size();
//     if(nums.size() % 2) return (double)nums[size/2];
//     else return ((double)nums[size/2] + (double)nums[size/2 - 1]) / 2;
// }

// //快排每次递归结束后都会把pivot_position所在的元素排到最终位置上，求中位数只用判断中间两个数或中间一个数，
// //故只需要将中间的数排到最终位置即可
// void MedianFinder::QuickSort(int& median_idx, int left, int right)
// {
//     if(left>=right) return;
//     int pivot_position = Partition(left, right);
//     if (pivot_position<median_idx)
//     {
//         QuickSort(median_idx, pivot_position+1, right);
//     }
//     else if(pivot_position>median_idx)
//     {
//         QuickSort(median_idx, left, pivot_position-1);
//     }
//     else
//         return ;
// }

// //因为添加元素都是添加到vector末尾，所以如果要排序肯定是添加的元素小于vector末尾的元素了，
// //添加的元素肯定是要排序的，那从最右边开始排效率会高些
// int MedianFinder::Partition(int left, int right)
// {
//     int pivot = nums[right];
//     while (left<right)
//     {
//         while(left<right && nums[left]<=pivot) left++;
//         nums[right] = nums[left];
//         while(left<right && nums[right]>=pivot) right--;
//         nums[left] = nums[right];
//     }
//     nums[right] = pivot;
//     return right;
// }

// //二分查找插入排序
// //时间复杂度O(N)(时间复杂度=查找O(logN)+排序O(N)=O(N))
// //空间复杂度O(1)
// class MedianFinder
// {
// private:
//     /* data */
// public:
//     MedianFinder(/* args */);
//     ~MedianFinder();
//     void addNum(int);
//     double findMedian();

// private:
//     vector<int> nums;
// };

// MedianFinder::MedianFinder(/* args */)
// {
// }

// MedianFinder::~MedianFinder()
// {
// }

// void MedianFinder::addNum(int num)
// {
//     if(nums.empty() || num>nums.back()) nums.push_back(num);
//     else
//     {
//         nums.push_back(num);

//         int left = 0, right = nums.size()-2;
//         while(left<=right)
//         {
//             int mid = (left+right)/2;
//             if(nums[mid]<=num) left = mid+1;
//             else right = mid-1;
//         }

//         for(int i=nums.size()-2; i>=right+1; i--)
//         {
//             nums[i+1] = nums[i];
//         }
//         nums[right+1] = num;
//     }
// }

// double MedianFinder::findMedian()
// {
//     if(nums.empty()) return 0;
//     int size = nums.size();
//     if(size % 2) return (double)nums[size/2];
//     else return ((double)nums[size/2 - 1] + (double)nums[size/2]) / 2;
// }


//用两个堆各维护一半的数字。用大根堆维护前一半小的数字，用小根堆维护后一半的数字。
//这样大根堆堆顶就是前一半数字的最大值，小根堆堆顶就是后一半数字的最小值。中位数就是这两个数的一个或两个
//插入方式：插入数据时，如果两个堆的元素个数相同，则先插入小根堆，再将小根堆堆顶元素插入大根堆，这样可以保证小根堆的元素都大于大根堆
//如果两个堆的元素个数不同，则先插入大根堆，再将大根堆堆顶元素插入小根堆，保证小根堆元素都大于大根堆。
//按这样的方式插入，就能保证当元素个数为偶数时，中位数等于两个堆的堆顶元素相加/2，当元素个数为奇数时，大根堆比小根堆多一个元素，中位数为大根堆堆顶元素。
//时间复杂度：O(logN)(堆的插入时间复杂度为O(logN)，查找中位数的时间复杂度为O(1)，故总时间复杂度为O(logN))
//空间复杂度：O(N)，两个堆各存储一半的元素，元素总个数为N
class MedianFinder
{
public:
    MedianFinder();
    ~MedianFinder();
    void addNum(int);
    double findMedian();

private:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
};

MedianFinder::MedianFinder()
{
}

MedianFinder::~MedianFinder()
{
}

void MedianFinder::addNum(int num)
{
    if(q1.size()==q2.size())
    {
        q2.push(num);
        q1.push(q2.top());
        q2.pop();
    }
    else
    {
        q1.push(num);
        q2.push(q1.top());
        q1.pop();
    }
}

double MedianFinder::findMedian()
{
    if(q1.size()==q2.size())
    {
        return ((double)q1.top() + (double)q2.top()) / 2;
    }
    else
    {
        return (double)q1.top();
    }
    
}


int main(int argc, char const *argv[])
{
    //vector<int> nums = {1,4,3,2};
    MedianFinder obj;
    obj.addNum(12);
    obj.addNum(10);
    obj.addNum(13);
    obj.addNum(11);
    obj.addNum(5);
    obj.addNum(15);
    double param1 = obj.findMedian();
    obj.addNum(2);
    double param2 = obj.findMedian();
    
    return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */