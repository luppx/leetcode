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
	int findBottomLeftValue(TreeNode* root);
};

int Solution::findBottomLeftValue(TreeNode* root)
{
	if(root==NULL) return -1;

	int curLevelLeft = 0;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		int size = q.size();
		curLevelLeft = q.front()->val;
		for(int i=0; i<size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
	return curLevelLeft;
}

int main()
{
	return 0;
}

