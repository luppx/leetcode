#include <cstddef>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public: 
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

private:
        TreeNode* createRoot(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right);
        unordered_map<int, int> map;
};

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
        if(preorder.empty() || inorder.empty() || (preorder.size()!=inorder.size())) return NULL;
        map = {}; 
        for(int i=0; i<inorder.size(); i++)
        {   
                map[inorder[i]] = i;
        }   
        TreeNode* root = createRoot(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
}

TreeNode* Solution::createRoot(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right)
{
        if(pre_left>pre_right) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_left]);
        if(pre_left==pre_right) return root;
        
        //根节点在中序序列的位置
        int in_root = map[preorder[pre_left]];

        //左子树长度
        int left_len = in_root-in_left;

        root->left = createRoot(preorder, pre_left+1, pre_left+left_len, inorder, in_left, in_root-1);
        root->right = createRoot(preorder, pre_left+left_len+1, pre_right, inorder, in_root+1, in_right);
        return root;
}


int main()
{
    vector<int> pre = {1,2};
    vector<int> in = {2,1};
    
    Solution obj;
    TreeNode* result = obj.buildTree(pre, in);
    return 0;
}
