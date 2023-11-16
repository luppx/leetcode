#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings);
};

//贪心，遍历两次数组，一次从左向右，一次从右向左。时间复杂度O(N)，空间复杂度O(N)
int Solution::candy(vector<int>& ratings) {
    if(ratings.empty()) return 0;
    else if(ratings.size()<2) return 1;

    int n = ratings.size();
    vector<int> left(n,1);
    vector<int> right(n,1);

    //从左往右遍历数组
    for(int i=1; i<n; i++)
    {
        if(ratings[i]>ratings[i-1]) left[i] = left[i-1]+1;
    }

    //从右往左遍历数组
    for(int i=n-1; i>0; i--)
    {
        if(ratings[i-1]>ratings[i]) right[i-1] = right[i]+1;
    }

    int res=0;
    for(int i=0; i<n; i++)
    {
        res += max(left[i], right[i]);
    }
    return res;
}