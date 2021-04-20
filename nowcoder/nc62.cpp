#include <cstddef>
#include <cmath>
#include <algorithm>
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
    bool IsBalanced_Solution(TreeNode* root);

private:
    int DFS(TreeNode* root);
};

bool Solution::IsBalanced_Solution(TreeNode* root)
{
    if(root==nullptr) return true;
    return DFS(root)!=-1;
}

int Solution::DFS(TreeNode* root)
{
    if(root==nullptr) return 0;
    int left_height = DFS(root->left);
    if(left_height==-1) return -1;
    int right_height = DFS(root->right);
    if(right_height==-1) return -1;

    if(abs(left_height-right_height)>1) return -1;
    return max(left_height, right_height)+1;
}

int main()
{
    return 0;
}