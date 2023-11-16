#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root);
};

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root)
{
    if(root==nullptr) return {};
    else if(root->left==nullptr && root->right==nullptr) return {{root->val}};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node;
        vector<int> tmp;
        int n=q.size();
        for(int i=0; i<n; i++)
        {
            node = q.front();
            q.pop();
            tmp.emplace_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.emplace_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
}