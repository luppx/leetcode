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
    int sumNumbers(TreeNode* root);

private:
    int DFS(TreeNode* root, int sum);
};

int Solution::sumNumbers(TreeNode* root)
{
    if(root==nullptr) return 0;
    else if(root->left==nullptr && root->right==nullptr) return root->val;

    int res = DFS(root, 0);
    return res;
}

int Solution::DFS(TreeNode* root, int sum)
{
    if(root==nullptr) return 0;
    sum = sum*10 + root->val;
    if(root->left==nullptr && root->right==nullptr) return sum;

    return DFS(root->left, sum) + DFS(root->right, sum);
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(0);
    n1->left = n2;

    Solution obj;
    int result = obj.sumNumbers(n1);
    return 0;
}