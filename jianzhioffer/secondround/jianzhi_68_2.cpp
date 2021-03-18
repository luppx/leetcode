#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//class Solution
//{
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
//private:
//	bool DFS(TreeNode* root, TreeNode* target, vector<TreeNode*>& path);
//};
//
//
////DFS+回溯，找出从根节点到节点p的路径以及从根节点到q的路径，比较2条路径，最后一个相同节点即为最近父节点。
////时间复杂度O(N)，空间复杂度O(N)
//TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//	if(root==NULL || p==NULL || q==NULL) return NULL;
//	vector<TreeNode*> path_p={};
//	vector<TreeNode*> path_q={};
//	bool rp = DFS(root, p, path_p);
//	bool rq = DFS(root, q, path_q);
//	
//	TreeNode* result = root;
//	for(int i=0; i<path_p.size() && i<path_q.size(); i++)
//	{
//		if(path_p[i]==path_q[i]) result = path_p[i];
//		else break;
//	}
//	return result;
//	
//}
//
//bool Solution::DFS(TreeNode* root, TreeNode* target, vector<TreeNode*>& path)
//{
//	if(root==NULL) return false;
//	
//	path.push_back(root);	
//
//	if(root==target) return true;
//	
//	bool res = DFS(root->left, target, path) || DFS(root->right, target, path);
//
//	if(!res) path.pop_back();  //如果没有找到，表明这条路径不包含该节点，故弹出节点。如果找到了则不用弹出
//
//	return res;
//}

class Solution
{
public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); 
};


//后序遍历DFS。
//时间复杂度O(N)，空间复杂度O(N)
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
        if(root==NULL || root==p || root==q) return root;
        
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if(left==NULL && right==NULL) return NULL; //既不在左子树，也不在右子树，说明树中没有这两个节点，返回NULL
	else if(left==NULL && right) return right; //此时有2种情况：1.p、q都在右子树上，因为遍历碰到p或q时就返回，所以此时返回的肯定是最近子节点；2.p、q中的一个在右子树上，则返回该节点即可
	else if(left && right==NULL) return left; //同3
	return root; //left!=NULL&&right!=NULL,即p、q分别在当前节点的左右子树上，则当前节点便是最近公共祖先
	
}


int main()
{
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(5);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(6);
 	TreeNode* n5 = new TreeNode(2);
	TreeNode* n6 = new TreeNode(0);
	TreeNode* n7 = new TreeNode(8);
	TreeNode* n10 = new TreeNode(7);
	TreeNode* n11 = new TreeNode(4);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n5->left = n10;
	n5->right = n11;

	Solution obj;
	TreeNode* result = obj.lowestCommonAncestor(n1, n2, n11);
	return 0;

}

