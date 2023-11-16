#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x=0, TreeNode* l=nullptr, TreeNode* r=nullptr):val(x),left(l),right(r) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root);
};

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    if(root==nullptr) return {};
    if(root->left==nullptr && root->right==nullptr) return {{root->val}};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node;
        vector<int> tmp;
        int n=q.size();
        while(n--)
        {
            node = q.front();
            q.pop();
            tmp.emplace_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.emplace_back(tmp);
    }
    return res;
}

int main()
{
    return 0;
}