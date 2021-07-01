#include <cstdio>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;

        Node* leftestNode = root;
        while(leftestNode->left!=nullptr)
        {
            Node* head = leftestNode;
            while(head!=nullptr)
            {
                head->left->next = head->right;

                if(head->next!=nullptr)
                {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftestNode = leftestNode->left;
        }
        return root;
    }
};

int main()
{
    return 0;
}