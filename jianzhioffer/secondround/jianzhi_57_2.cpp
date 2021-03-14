#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target);
};

// //暴力法。时间复杂度O(N^2)，空间复杂度O(N)(辅助数组需O(N)空间)
// vector<vector<int>> Solution::findContinuousSequence(int target)
// {
//     vector<vector<int>> res {};
//     if(target<=0) return res;
//     vector<int> tmp_sum {};
//     int cur_sum = 0;
//     for (int i = 1; i <= target/2; i++)
//     {
//         for(int j = i; j<=target; j++)
//         {
//             tmp_sum.push_back(j);
//             cur_sum += j;
//             if(cur_sum>target)
//             {
//                 tmp_sum.clear();
//                 cur_sum = 0;
//                 break;
//             }
//             else if(cur_sum==target)
//             {
//                 res.push_back(tmp_sum);
//                 tmp_sum.clear();
//                 cur_sum = 0;
//                 break;
//             }
//         }

//     }
//     return res;
// }


//方法二，滑动窗口。时间复杂度O(N)，空间复杂度O(1)
//注，为了编程时的方便，把滑动窗口想象成左闭右开区间
vector<vector<int>> Solution::findContinuousSequence(int target)
{
    vector<vector<int>> res {};
    if(target<=0) return res;
    int left = 1, right = 2;
    int cur_sum = 1;
    while (left<=(target/2))
    {
        if(cur_sum<target)
        {
            cur_sum += right;
            right++;
        }
        else if(cur_sum>target)
        {
            cur_sum -= left;
            left++;
        }
        else
        {
            vector<int> tmp {};
            for (int i = left; i < right; i++)
            {
                tmp.push_back(i);
            }
            res.push_back(tmp);
            cur_sum -= left;
            left++;
        }
        
    }
    return res;
}

int main(int argc, char const *argv[])
{
    Solution obj;
    vector<vector<int>> result = obj.findContinuousSequence(15);
    return 0;
}
