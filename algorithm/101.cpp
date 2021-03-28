#include <deque>
#include <cstddef>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//迭代
//class Solution
//{
//public:
//	bool isSymmetric(TreeNode* root);
//};
//
//bool Solution::isSymmetric(TreeNode* root)
//{
//	if(root==NULL) return false;
//	
//	deque<TreeNode*> dq = {};
//	dq.push_back(root->left);
//	dq.push_back(root->right);
//	
//	while(!dq.empty())
//	{
//		TreeNode* l = dq.front();
//		dq.pop_front();
//		TreeNode* r = dq.front();
//		dq.pop_front();
//		if(l==NULL && r==NULL) continue;
//		if((l!=NULL && r==NULL) || (l==NULL && r!=NULL) || (l->val!=r->val)) return false;
//		dq.push_back(l->left);
//		dq.push_back(r->right);
//		dq.push_back(l->right);
//		dq.push_back(r->left);
//	}
//	return true;
//}

//递归
class Solution
{
public:
        bool isSymmetric(TreeNode* root);

private:
	bool preorder(TreeNode* p, TreeNode* q);
};

bool Solution::isSymmetric(TreeNode* root)
{
        if(root==NULL) return false;
	return preorder(root, root);
}

bool Solution::preorder(TreeNode* p, TreeNode* q)
{
	if(p==NULL && q==NULL) return true;
	else if(p==NULL || q==NULL || p->val!=q->val) return false;
	return preorder(p->left, q->right) && preorder(p->right, q->left);
}


int main()
{
	return 0;
}


