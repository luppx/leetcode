#include <vector>
#include <queue>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode* root);
};

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root)
{
	if(root==NULL) return {};
	queue<TreeNode*> q;
	vector<vector<int>> res = {};
	
	q.push(root);
	int level = 0;
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
		
		if(level&1)
		{
			res.push_back(tmp);
		}
		else
		{
			vector<int> t;
			while(!tmp.empty())
			{
				t.push_back(tmp.back());
				tmp.pop_back();
			}
			res.push_back(t);
		}
		level++;
	}
	return res;
}

int main()
{
	return 0;
}

