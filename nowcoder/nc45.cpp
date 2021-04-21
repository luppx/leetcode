#include <vector>
#include <cstddef>
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
    vector<vector<int>> threeOrders(TreeNode* root);

private:
    void preorder(TreeNode* root, vector<int>& pre);
    void inorder(TreeNode* root, vector<int>& in);
    void postorder(TreeNode* root, vector<int>& post);
};

vector<vector<int>> Solution::threeOrders(TreeNode* root)
{
    if(root==nullptr) return {};

    vector<int> pre = {};
    vector<int> in = {};
    vector<int> post = {};
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    return {pre, in, post};
}

void Solution::preorder(TreeNode* root, vector<int>& pre)
{
    if(root==nullptr) return;

    pre.push_back(root->val);
    preorder(root->left, pre);
    preorder(root->right, pre);
    return ;
}

void Solution::inorder(TreeNode* root, vector<int>& in)
{
    if(root==nullptr) return ;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
    return ;
}

void Solution::postorder(TreeNode* root, vector<int>& post)
{
    if(root==nullptr) return ;

    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->val);
    return ;
}

int main()
{
    return 0;
}