#include <vector>
#include <cstddef>
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
	vector<vector<int>> pathSum(TreeNode* root, int target);

private:
	void preorder(TreeNode* root, int target, vector<int>& path);
	vector<vector<int>> res;
};

vector<vector<int>> Solution::pathSum(TreeNode* root, int target)
{	
	res={};
	if(root==NULL) return res;
	
	vector<int> path={};
	preorder(root, target, path);
	return res;
}

void Solution::preorder(TreeNode* root, int target, vector<int>& path)
{
	if(root==NULL) return;
	
	path.push_back(root->val);
	if(target==root->val && root->left==NULL && root->right==NULL)
	{
		res.push_back(path);
		path.pop_back();
		return;
	}	

	preorder(root->left, target-root->val, path);
	preorder(root->right, target-root->val, path);
	path.pop_back();
	return;
}

int main()
{
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(8);
	TreeNode* n4 = new TreeNode(11);
	TreeNode* n6 = new TreeNode(13);
	TreeNode* n7 = new TreeNode(4);
	TreeNode* n8 = new TreeNode(7);
	TreeNode* n9 = new TreeNode(2);
	TreeNode* n14 = new TreeNode(5);
	TreeNode* n15 = new TreeNode(1);
	
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n6;
	n3->right = n7;
	n4->left = n8;
	n4->right = n9;
	n7->left = n14;
	n7->right = n15;

	Solution obj;
	vector<vector<int>> result = obj.pathSum(n1, 22);
	return 0;

}


