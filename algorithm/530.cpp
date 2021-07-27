#include <climits>
using namespace std;

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
    int getMinimumDifference(TreeNode* root);

private:
    void inOrder(TreeNode* root);
    int res;
    int preVal;
};

int Solution::getMinimumDifference(TreeNode* root) {
    if(root==nullptr) return 0;

    res = INT_MAX;
    preVal = -1;
    inOrder(root);
    return res;
}

void Solution::inOrder(TreeNode* root)
{
    if(root==nullptr) return;

    inOrder(root->left);
    if(preVal!=-1)
    {
        res = root->val - preVal < res ? root->val - preVal : res;
    }
    preVal = root->val;
    inOrder(root->right);
    return;
}