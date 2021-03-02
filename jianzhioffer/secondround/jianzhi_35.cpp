#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//哈希表。时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head==NULL) return NULL;

//         unordered_map<Node*, Node*> pairs;
//         Node* old_cur = head;
//         while (old_cur!=NULL)
//         {
//             pairs[old_cur] = new Node(old_cur->val);
//             old_cur = old_cur->next;
//         }
//         old_cur = head;
//         while (old_cur!=NULL)
//         {
//             pairs[old_cur]->next = pairs[old_cur->next];
//             pairs[old_cur]->random = pairs[old_cur->random];
//             old_cur = old_cur->next;
//         }
        
//         return pairs[head];
//     }   
// };

//DFS。可以把链表看成一个图，则可用DFS和BFS求解。
//时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head==NULL) return NULL;
//         return DFS(head);
//     }

//     Node* DFS(Node* node)
//     {
//         if(node==NULL) return NULL;
//         else if(pairs.find(node)!=pairs.end())
//         {
//             return pairs[node];
//         }
//         Node* new_node = new Node(node->val);
//         pairs[node] = new_node;
//         new_node->next = DFS(node->next);
//         new_node->random = DFS(node->random);
//         return pairs[node];
//     }

// private:
//     unordered_map<Node*, Node*> pairs;
// };

// //BFS。时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head==NULL) return NULL;
//         Node* cur = head;
//         pairs[cur] = new Node(head->val);
//         queue<Node*> q;
//         q.push(cur);
//         while (!q.empty())
//         {
//             Node* node = q.front();
//             q.pop();
 
//             if(node->next!=NULL && pairs.find(node->next)==pairs.end())
//             {
//                 q.push(node->next);
//                 pairs[node->next] = new Node(node->next->val);
//             }
//             if(node->random!=NULL && pairs.find(node->random)==pairs.end())
//             {
//                 q.push(node->random);
//                 pairs[node->random] = new Node(node->random->val);
//             }
//             pairs[node]->next = pairs[node->next];
//             pairs[node]->random = pairs[node->random];
//         }
        
//         return pairs[head];
//     }

// private:
//     unordered_map<Node*, Node*> pairs;
// };

//就地复制。时间复杂度O(N)，空间复杂度O(1)
//在原链表基础上每个节点都复制一次。比如原链表1-2-3，则插入复制的节点，变成1-1-2-2-3-3
//这样重复的节点就是新节点，要求new_node->random就可以直接赋值new_node->random = old_node->random->next
//时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* cur = head;
        while (cur!=NULL)
        {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur!=NULL)
        {
            if(cur->random!=NULL)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* new_head = head->next;
        Node* new_cur = new_head;
        cur = head;
        while (cur!=NULL)
        {
            Node* tmp = new_cur->next;
            if(tmp!=NULL)
            {
                new_cur->next = tmp->next;
            }
            cur->next = tmp; 
            new_cur = new_cur->next;
            cur = cur->next; 
        }

        return new_head;
    }

};

int main(int argc, char const *argv[])
{
    Node n1 = Node(7);
    Node n2 = Node(13);
    Node n3 = Node(11);
    Node n4 = Node(10);
    Node n5 = Node(1);
    n1.next = &n2;
    n2.next = &n3;
    n2.random = &n1;
    n3.next = &n4;
    n3.random = &n4;
    n4.next = &n5;
    n4.random = &n2;
    
    n5.random = &n1;

    Solution obj;
    Node* result = obj.copyRandomList(&n1);
    return 0;
}
