b0VIM 7.4      � Z`W �'  root                                    aliyunecs1                              /home/leetcode/algorithm/328.cpp                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   3210    #"! U                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 tp           @                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ad  �  
     @       �  �  �  �  �  �  �  {  x  w  h  f  ^  6  3  2       �  �  �  `  <  ;  �      �  �  �  �  �  �  g  f  '  �  �  �  �  �  l  W  U  T  I  G  &    �
  �
  �
  �
  �
  �
  q
  a
  `
  Q
  (
  '
  
  
  
  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                } 	return 0;  	ListNode* result = obj.oddEvenList(n1); 	Solution obj;  	n4->next = n5; 	n3->next = n4; 	n2->next = n3; 	n1->next = n2;  	ListNode* n5 = new ListNode(5); 	ListNode* n4 = new ListNode(4); 	ListNode* n3 = new ListNode(3); 	ListNode* n2 = new ListNode(2); 	ListNode* n1 = new ListNode(1); { int main()  }         return head;         prevO->next = EvenHead;         }    		if(prevE!=NULL) prevE->next = curE; 		if(prevO!=NULL) prevO->next = curO; 		 		curE = (curO!=NULL && curO->next!=NULL) ? curO->next : NULL; 		curO = (curE!=NULL && curE->next!=NULL) ? curE->next : NULL;                  prevE = curE;                 prevO = curO;         {            while(curO!=NULL || curE!=NULL)          prevE->next = curE;         prevO->next = curO;              ListNode* curE = prevE->next->next!=NULL ? prevE->next->next : NULL;  //第二个偶数节点。通过上面的if可确定链表长度至少为3，当为3时，只有一个偶数节点，所以要判断是否为NULL         ListNode* curO = prevO->next->next;  //第二个奇数节点          ListNode* prevE = EvenHead;         ListNode* prevO = head;         ListNode* EvenHead = head->next;              if(head==NULL || head->next==NULL || head->next->next==NULL) return head; { ListNode* Solution::oddEvenList(ListNode* head)  }; 	ListNode* oddEvenList(ListNode* head); public: { class Solution  }; 	ListNode(int x): val(x), next(NULL) {} 	ListNode* next = NULL; 	int val; { struct ListNode  using namespace std; #include <cstddef> 