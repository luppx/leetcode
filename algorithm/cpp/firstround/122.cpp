#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices) {
    if(prices.size()<2) return 0;

    int res = 0;
    int pre = prices[0];

    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i]<pre) pre = prices[i];
        else if(prices[i]>pre && (i==prices.size()-1 || (prices[i]>prices[i+1])))  //后面股票要降了
        {
            res += prices[i]-pre;
            if(i==prices.size()-1) break;
            pre = prices[i+1];
            i++;
        }
    }
    return res;
}