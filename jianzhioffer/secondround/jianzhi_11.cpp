#include <vector>
using namespace std;

// //方法一，遍历。时间复杂度O(N)，空间复杂度O(1)
// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         if (numbers.empty())
//         {
//             return -1;
//         }
//         int min_num = numbers.back();
//         for (int i = numbers.size()-2; i >= 0; i--)
//         {
//             if (numbers[i]>min_num)
//                 break;
//             else
//                 min_num = numbers[i];
//         }
//         return min_num;
//     }
// };

//方法二，二分查找，时间复杂度O(logN)，空间复杂度O(1)
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty())
        {
            return -1;
        }
        int low = 0;
        int high = numbers.size()-1;
        while (low<high)
        {
            int pivot = (low+high)/2;
            if (numbers[pivot]<numbers[high])
            {
                high = pivot;
            }
            else if (numbers[pivot]>numbers[high])
            {
                low = pivot + 1;
            }
            else
            {
                high--;
            }        
        }
        return numbers[low];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n = {3,1};
    Solution obj;
    int result = obj.minArray(n);
    return 0;
}
