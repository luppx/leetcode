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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;

        if((root->val>p->val && root->val<q->val) || (root->val<p->val && root->val>q->val)) //在root左右子树上，直接返回root
        {
            return root;
        }
        else if(root->val>p->val && root->val>q->val)  //在root左子树上，找到第一个目标节点，它就是两个节点的最近公共祖先
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else return lowestCommonAncestor(root->right, p, q);  //在root右子树上，找到第一个目标节点，它就是两个节点的最近公共祖先
    }
};