#include <vector>
#include <stack>
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
	vector<int> inorderTraversal(TreeNode* root);
};

// vector<int> Solution::inorderTraversal(TreeNode* root)
// {
// 	if(root==NULL) return {};
	
// 	vector<int> res = {};
// 	stack<TreeNode*> s;
	
// 	while(!s.empty() || root!=NULL)
// 	{
// 		while(root!=NULL)
// 		{
// 			s.push(root);
// 			root = root->left;
// 		}

// 		root = s.top();
// 		s.pop();
// 		res.push_back(root->val);
// 		root = root->right;
// 	}
// 	return res;
// }

vector<int> Solution::inorderTraversal(TreeNode* root)
{
    if(root==nullptr) return {};
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    
    while(!st.empty())
    {
        TreeNode* node = st.top();
        if(node!=nullptr)
        {
            st.pop();
            if(node->right) st.push(node->right);

            st.push(node);
            st.push(nullptr);

            if(node->left) st.push(node->left);
        }
        else
        {
            st.pop();
            res.emplace_back(st.top()->val);
            st.pop();
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
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n9 = new TreeNode(9);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	// n4->left = n8;
	n4->right = n9;

	Solution obj;
	vector<int> result = obj.inorderTraversal(n1);
	return 0;
}

