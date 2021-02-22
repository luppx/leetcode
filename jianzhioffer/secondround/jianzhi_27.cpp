#include <cstddef>
#include <vector>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// //bfs,时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     TreeNode* mirrorTree(TreeNode* root) {
//         if(root==NULL) return NULL;
//         else if(root->left==NULL && root->right==NULL) return root;
//         vector<TreeNode*> node_list;
//         node_list.push_back(root);
//         while (!node_list.empty())
//         {
//             TreeNode* node = node_list.back();
//             node_list.pop_back();
//             if(node->left!=NULL) node_list.push_back(node->left);
//             if(node->right!=NULL) node_list.push_back(node->right);
//             swap(node->left, node->right);
//         }
//         return root;
//     }
// };

//递归,时间复杂度O(N)，空间复杂度O(N)
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode t11 = TreeNode(4);
    TreeNode t12 = TreeNode(2);
    TreeNode t13 = TreeNode(7);
    TreeNode t14 = TreeNode(1);
    TreeNode t15 = TreeNode(3);
    TreeNode t16 = TreeNode(6);
    TreeNode t17 = TreeNode(9);

    t11.left = &t12;
    t11.right = &t13;
    t12.left = &t14;
    t12.right = &t15;
    t13.left = &t16;
    t13.right = &t17;

    Solution obj;
    TreeNode* result = obj.mirrorTree(&t11);
    return 0;
}