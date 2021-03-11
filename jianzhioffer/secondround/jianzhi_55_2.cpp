#include <cstddef>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode* root);

private:
    int DFS(TreeNode* root);
};

//DFS，此处用后序遍历。时间复杂度O(N)，空间复杂度O(N)
bool Solution::isBalanced(TreeNode* root)
{
    if(root==NULL) return true;
    return DFS(root)!=-1;
}

int Solution::DFS(TreeNode* root)
{
    if(root==NULL) return 0;
    int left_depth = DFS(root->left);
    if(left_depth==-1) return -1;

    int right_depth = DFS(root->right);
    if(right_depth==-1) return -1;

    if(abs(left_depth-right_depth)>1) return -1;
    else return max(left_depth, right_depth)+1;
}

int main(int argc, char const *argv[])
{
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    Solution obj;
    int result = obj.isBalanced(n1);
    return 0;
}