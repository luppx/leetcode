#include <vector>
#include <cstddef>
#include <map>
using namespace std;

struct Interval
{
    int start;
    int end;
};

struct Edge
{
    int end;
    int val;
    Edge(int e, int s): val(s), end(e) {}
};

class Solution
{
public:
    int solve(int n, vector<Interval>& treeEdge, vector<int>& edgeValue);

private:
    void DFS(map<int, vector<Edge*>>& graph, int from, int prev, int path, vector<int>& res);
};

int Solution::solve(int n, vector<Interval>& treeEdge, vector<int>& edgeValue)
{
    if(treeEdge.empty() || edgeValue.size()!=n-1 || treeEdge.size()!=n-1 || treeEdge.size()!=edgeValue.size()) return 0;
    
    //构建无向图
    map<int, vector<Edge*>> graph;
    for (int i = 0; i < n-1; i++)
    {
        int start = treeEdge[i].start;
        int end = treeEdge[i].end;
        int weight = edgeValue[i];
        Edge* e1 = new Edge(end, weight);

        if(graph.find(start)==graph.end())
        {
            vector<Edge*> tmp = {};
            graph[start] = tmp;
        }
        graph[start].push_back(e1);

        Edge* e2 = new Edge(start, weight);
        if(graph.find(end)==graph.end())
        {
            vector<Edge*> tmp = {};
            graph[end] = tmp;
        }
        graph[end].push_back(e2);   
    }
    
    //1.先从根节点出发，一直探索到最底层，也就是离根节点最远的一个端点。这个端点必定是最后所求的最长距离的其中一个端点
    //2.找到这个端点，然后从这个端点出发，探索距离此点最远的点。

    vector<int> remote(2, 0);  // remote[0] 代表以0为起点的最长路径长度， remote[1]代表最长路径的终点
    DFS(graph, 0, -1, 0, remote);

    vector<int> res(2,0);
    DFS(graph, remote[1], -1, 0, res);
    return res[0];
}

void Solution::DFS(map<int, vector<Edge*>>& graph, int from, int prev, int path, vector<int>& res)
{
    vector<Edge*> edges = graph[from];
    for(auto edge: edges)
    {
        if(edge->end!=prev)
        {
            path += edge->val;
            if(path>res[0])
            {
                res[0]=path;
                res[1]=edge->end;
            }
            DFS(graph, edge->end, from, path, res);
            path -= edge->val;  //回溯
        }
    }
}

int main()
{
    return 0;
}