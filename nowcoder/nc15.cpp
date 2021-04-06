#include <vector>
#include <cstddef>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root);
};

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	if(root==NULL) return {};
	queue<TreeNode*> q;
	q.push(root);
	vector<vector<int>> res = {};
	while(!q.empty())
	{
		int size = q.size();
		vector<int> tmp = {};
		for(int i=0; i<size; i++)
		{	
			TreeNode* node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
			tmp.push_back(node->val);
		}
		res.push_back(tmp);
	}
	return res;
}

int main()
{
	return 0;
}

