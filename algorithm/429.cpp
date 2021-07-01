#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node()=default;
    Node(int _val)
    {
        val = _val;
    }
    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root);
};

vector<vector<int>> Solution::levelOrder(Node* root)
{
    if(root==nullptr) return {};
    else if(root->children.empty()) return {{root->val}};

    vector<vector<int>> res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* node;
        vector<int> tmp;
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            node = q.front();
            q.pop();
            tmp.emplace_back(node->val);
            for(auto child : node->children)
            {
                if(child) q.push(child);
            }
        }
        res.emplace_back(tmp);
    }
    return res;
}

int main()
{
    return 0;
}