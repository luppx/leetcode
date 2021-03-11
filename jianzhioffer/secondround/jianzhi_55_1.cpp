#include <cstddef>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {};
};

// class Solution
// {
// public:
//     int maxDepth(TreeNode* root);

// private:
//     int DFS(TreeNode* root);
// };

// //DFS。时间复杂度O(N)，空间复杂度O(N)(递归占用O(N))
// int Solution::maxDepth(TreeNode* root)
// {
//     if(root==NULL) return 0;
//     return DFS(root);;
// }

// int Solution::DFS(TreeNode* root)
// {
//     if(root==NULL) return 0;
//     return max(DFS(root->left), DFS(root->right)) + 1;
// }

class Solution
{
public:
    int maxDepth(TreeNode* root);

private:
    int BFS(TreeNode* root);
};

//BFS。时间复杂度O(N)，空间复杂度O(N)(递归占用O(N))
int Solution::maxDepth(TreeNode* root)
{
    if(root==NULL) return 0;
    return BFS(root);
}

int Solution::BFS(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        res++;
        int size = q.size();
        while (size>0)
        {
            TreeNode* node = q.front();
            q.pop();
            size--;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return res;
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
    int result = obj.maxDepth(n1);
    return 0;
}