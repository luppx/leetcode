struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right) return root; //p q在root的左右子树上
    else if(root==p || root==q) return root; //p q中一个为祖先节点，另一个在它的左子树或右子树上 或者 先找到p q中的一个
    else if(left) return left; //左子树找到1个或2个都找到
    else if(right) return right; //右子树找到1个或2个都找到
    else return nullptr;  //左右子树都没有找到，则返回空指针
}