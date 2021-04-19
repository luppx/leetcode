#include <vector>
#include <cstddef>
#include <map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> solve(vector<int>& preorder, vector<int>& inorder);

private:
    TreeNode* buildTree(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right);
    map<int,int> m;
};

vector<int> Solution::solve(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty() || preorder.size()!=inorder.size()) return {};

    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }

    //建树    
    TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

    //右视图
    vector<int> res = {};
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        TreeNode* node = nullptr;
        
        for (int i = 0; i < size; i++)
        {
            node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(node->val);
    }

    return res;
}

TreeNode* Solution::buildTree(vector<int>& preorder, int pre_root, int pre_right, vector<int>& inorder, int in_left, int in_right)
{
    if(in_left>in_right) return NULL;

    int in_root_idx = m[preorder[pre_root]];
    int pre_left_subtree_len = in_root_idx-in_left;

    TreeNode* node = new TreeNode(preorder[pre_root]);
    node->left = buildTree(preorder, pre_root+1, pre_root+pre_left_subtree_len, inorder, in_left, in_root_idx-1);
    node->right = buildTree(preorder, pre_root+pre_left_subtree_len+1, pre_right, inorder, in_root_idx+1, in_right);
    return node;
}

int main()
{
    vector<int> preorder = {1,2,4,5,3};
    vector<int> inorder = {4,2,5,1,3};
    Solution obj;
    vector<int> result = obj.solve(preorder, inorder);
    return 0;
}