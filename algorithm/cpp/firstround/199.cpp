#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x=0, TreeNode* l=nullptr, TreeNode* r=nullptr):val(x), left(l),right(r){}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root);
};

vector<int> Solution::rightSideView(TreeNode* root)
{
    if(root==nullptr) return {};
    else if(root->left==nullptr && root->right==nullptr) return {root->val};

    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node;
        int n=q.size();
        for(int i=0; i<n; i++)
        {
            node = q.front();
            q.pop();
            if(i==n-1) res.emplace_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return res;
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    
    Solution obj;
    vector<int> result = obj.rightSideView(n1);
    return 0;
}