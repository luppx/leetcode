#include <vector>
#include <queue>
using namespace std;

// //dfs，时间复杂度O(mn)，空间复杂度O(mn)(建立了一个辅助数组用于记录该点是否已被访问过)
// class Solution {
// public:
//     int movingCount(int m, int n, int k) {
//         if(m<=0 || n<=0)
//             return 0;
//         rows = m;
//         cols = n;
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         return dfs(visited, 0, 0, k);
//     }

// private:
//     int rows, cols;
//     int dfs(vector<vector<bool>>& visited, int i, int j, int& k){
//         //因为是从左上角(0,0)开始的，所以只用向下和向右走，必定能遍历到所有解，则判断边界溢出的条件也不用考虑向左和向上的情况
//         if(i>=rows || j>=cols || (i%10 + i/10 + j%10 + j/10)>k || visited[i][j])
//         {
//             return false;
//         }
//         visited[i][j] = true;
//         return 1 + dfs(visited, i+1, j, k) + dfs(visited, i, j+1, k);
//     }
// };

//bfs，时间复杂度O(mn)，空间复杂度O(mn)(建立了一个辅助数组用于记录该点是否已被访问过)
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m<=0 || n<=0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        int res = 0;
        q.push({0,0});
        while (!q.empty())
        {
            vector<int> tmp;
            tmp = q.front();
            q.pop();
            int i = tmp[0];
            int j = tmp[1];
            if(i>=m || j>=n || (i%10 + i/10 + j%10 + j/10)>k || visited[i][j])
                continue;
            visited[i][j] = true;
            res++;
            q.push({i+1,j});
            q.push({i,j+1});
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    int num = obj.movingCount(3,2,17);
    return 0;
}
