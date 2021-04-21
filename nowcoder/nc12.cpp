#include <vector>
#include <cstddef>
#include <map>
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
    TreeNode* reConstructBinaryTree(vector<int>& preorder, vector<int>& inorder);

private:
    TreeNode* buildTree(vector<int>& preorder, int pre_root, int pre_right, vector<int>& inorder, int in_left, int in_right);
    map<int, int> m;
};

TreeNode* Solution::reConstructBinaryTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty() || preorder.size()!=inorder.size()) return nullptr;

    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    
    return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

TreeNode* Solution::buildTree(vector<int>& preorder, int pre_root, int pre_right, vector<int>& inorder, int in_left, int in_right)
{
    if(in_left>in_right) return nullptr;

    TreeNode* node = new TreeNode(preorder[pre_root]);
    int in_root_idx = m[preorder[pre_root]];
    int leftSubtreeLen = in_root_idx - in_left;

    node->left = buildTree(preorder, pre_root+1, pre_root+leftSubtreeLen, inorder, in_left, in_root_idx-1);
    node->right = buildTree(preorder, pre_root+leftSubtreeLen+1, pre_right, inorder, in_root_idx+1, in_right);
    return node;
}

int main()
{
    return 0;
}