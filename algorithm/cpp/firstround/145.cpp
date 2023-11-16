#include <vector>
#include <stack>
#include <cstddef>
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
    vector<int> postorderTraversal(TreeNode* root);
};

vector<int> Solution::postorderTraversal(TreeNode* root)
{
        if(root==NULL) return {}; 
        vector<int> res = {}; 
        stack<TreeNode*> s;
        TreeNode* prev = NULL; //前一个遍历的节点
    
        while(!s.empty()|| root!=NULL)
        {   
                while(root!=NULL)
                {   
                        s.push(root);
                        root = root->left;
                }   
    
                root = s.top();
                s.pop();
                if(root->right==NULL || root->right==prev)  //如果右节点为空或者已经遍历过右节点
                {
                        res.push_back(root->val);
                        prev = root;
                        root = NULL;  //为了避开内部的while，以避免重复将节点入栈
                }
                else
                {
                        s.push(root);
                        root = root->right;
                }
        }
        return res;
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    Solution obj;
    vector<int> result = obj.postorderTraversal(n1);
    delete n1;
    delete n2;
    delete n3;
    return 0;
}

