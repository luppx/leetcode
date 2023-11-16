#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};


//暴力，时间复杂度O(N^2)，空间复杂度O(1)
// int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     if(gas.empty() || cost.empty() || gas.size()!=cost.size()) return -1;

//     int n = gas.size();
//     for(int start=0; start<n; start++)
//     {
//         int totalGas = 0;
//         int i = start;
//         for(; i<start+n; i++)
//         {
//             totalGas += gas[i%n] - cost[i%n];
//             if(totalGas<0) break;
//         }
//         if(i==start+n && totalGas>=0) return start;
//     }
//     return -1;
// }

//优化，只用遍历一次数组，时间复杂度O(N)，空间复杂度O(1)
int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if(gas.empty() || cost.empty() || gas.size()!=cost.size()) return -1;

    int n = gas.size();
    int i = 0;
    while(i<n)
    {
        int j = i;
        int sumOfCost=0, sumOfGas=0;
        while(j<n)
        {
            sumOfGas += gas[j%n];
            sumOfCost += cost[j%n];
            if(sumOfGas<sumOfCost) break;

            j = (j+1)%n;
            if(j==i) return i;
        }
        
        //把加油站想象成一个圆，如果j<i，说明从第i-第n个加油站出发，都无法回到原点，而i前面的加油站都已经计算过了，所以肯定不存在满足条件的点，可以直接返回-1
        if(j<i) return -1;
        else i = j+1;  //从i触发最远能到达j，说明从第i-第j个加油站出发，都无法返回原点，否则到达第j个加油站时，肯定能到达第j+1个加油站，而现在到不了，说明i-j都不满足条件，所以直接从第j+1个加油站开始计算
    }
    return -1;
}