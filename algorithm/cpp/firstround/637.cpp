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
	vector<double> averageOfLevels(TreeNode* root);

};

vector<double> Solution::averageOfLevels(TreeNode* root)
{
	if(root==NULL) return {};
	vector<double> res = {};
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
		int size = q.size();
		double average = 0;
		for(int i=0; i<size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			average += node->val;
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		average /= size;
		res.push_back(average);
	}
	return res;
}

int main()
{
	return 0;
}

