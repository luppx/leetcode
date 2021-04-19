#include <cstddef>
#include <vector>
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
    int maxDepth(TreeNode* root);

private:
    int postorder(TreeNode* root);
};

int Solution::maxDepth(TreeNode* root)
{
    if(root==nullptr) return 0;
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return max(left_height,right_height)+1;
}

int main()
{
    return 0;
}