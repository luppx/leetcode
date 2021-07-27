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
    TreeNode* convertBST(TreeNode* root);

private:
    int preVal;
    TreeNode* reverseInOrder(TreeNode* root);
};

TreeNode* Solution::convertBST(TreeNode* root)
{
    if(root==nullptr) return root;

    preVal = 0;
    return reverseInOrder(root);
}


TreeNode* Solution::reverseInOrder(TreeNode* root) {
    if(root==nullptr) return root;

    root->right = reverseInOrder(root->right);
    root->val += preVal;
    preVal = root->val;
    root->left = reverseInOrder(root->left);
    return root;
}