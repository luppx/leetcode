# include <vector>
# include <stack>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//方法一：递归法
// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         if (!head)
//             return {};
//         vector<int> a = reversePrint(head->next);
//         a.push_back(head->val);
//         return a;
//     }
// };

//方法二：栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head)
            return {};
        stack<int> s;
        vector<int> res;
        while (head)
        {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    l1.next = &l2;
    l2.next = &l3;
    Solution obj;
    vector<int> result = obj.reversePrint(&l1);
    return 0;
}
