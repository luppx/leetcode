#include <cstddef>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
        Solution():maxpath(0) {}
        int longestUnivaluePath(TreeNode* root);

private:
        int dfs(TreeNode* root);
        int maxpath;
};


int Solution::longestUnivaluePath(TreeNode* root)
{
        if(root==NULL) return 0;
        dfs(root);
        return maxpath;
}

int Solution::dfs(TreeNode* root)
{
        if(root==NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftpath=0, rightpath=0;
        if(root->left!=NULL && root->left->val==root->val) leftpath = left+1;
        if(root->right!=NULL && root->right->val==root->val) rightpath = right+1;

        maxpath = max(maxpath, leftpath+rightpath);
        return max(leftpath, rightpath);
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(5);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n7;

    Solution obj;
    int result = obj.longestUnivaluePath(n1);
    delete n1, n2, n3, n4, n5, n7;
    return 0;
}

