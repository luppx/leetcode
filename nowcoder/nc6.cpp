#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x=0): val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode* root);

private:
    int dfs(TreeNode* root, int sum);
    int max_pathSum;
};

int Solution::maxPathSum(TreeNode* root)
{
    if(root==nullptr) return 0;
    else if(root->left==nullptr && root->right==nullptr) return root->val;
    max_pathSum = INT_MIN;
    int tmp = dfs(root, 0);
    return max_pathSum;
}

int Solution::dfs(TreeNode* root, int sum)  //后序遍历，时间复杂度O(logN)，空间复杂度O(logN)
{
    if(root==nullptr) return 0;
    int leftPathSum = dfs(root->left, sum);
    int rightPathSum = dfs(root->right, sum);
    int maxSubTreePathSum = max(leftPathSum, rightPathSum);
    
    int tmp1 = maxSubTreePathSum+root->val;
    int tmp2 = leftPathSum+rightPathSum+root->val;
    max_pathSum = max(max_pathSum, max(tmp1, max(tmp2, root->val)));

    return max(root->val, maxSubTreePathSum+root->val);
}

int main()
{
    TreeNode* n1 = new TreeNode(-2);
    TreeNode* n2 = new TreeNode(-1);
    // TreeNode* n3 = new TreeNode(3);
    // TreeNode* n4 = new TreeNode(4);
    // TreeNode* n5 = new TreeNode(5);
    // TreeNode* n6 = new TreeNode(6);
    // TreeNode* n7 = new TreeNode(7);
    
    n1->left = n2;
    // n1->right = n3;
    // n2->left = n4;
    // n2->right = n5;
    // n3->left = n6;
    // n3->right = n7;

    Solution obj;
    int result = obj.maxPathSum(n1);
    return 0;
}