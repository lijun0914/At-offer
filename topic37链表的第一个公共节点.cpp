/*
	输入两个链表，找出它们的第一个公共节点。 
	A:          a1 ? a2
                   ?
                     c1 ? c2 ? c3
                   ?            
B:     b1 ? b2 ? b3
*/
#include <list>
#include <stack>
#include <iostream>
using namespace std;
struct ListNode{
	int m_value;
	ListNode* m_pNext;
	ListNode(){}
	ListNode(int x):m_value(x),m_pNext(NULL){}
};
/*
	第二遍的遍历 会走出第一遍的公共节点前的差值 
*/
ListNode* getIntersection(ListNode* headA,ListNode* headB){
	ListNode* l1=headA;
	ListNode* l2=headB;
	if(l1==NULL||l2==NULL)
		return NULL;
	while(l1!=NULL&&l2!=NULL&&l1!=l2){
		l1=l1->m_pNext;
		l2=l2->m_pNext;
		if(l1==l2) return l1;
		if(l1==NULL) l1=headB;
		if(l2==NULL) l2=headA;
	}
	return l1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
       ListNode *l1=headA;
       ListNode *l2=headB;
       if(l1==NULL||l2==NULL)
        return NULL;
       while(l1!=NULL&&l2!=NULL&l1!=l2)
       {
           l1=l1->m_pNext;
           l2=l2->m_pNext;
           if(l1==l2) return l1;
           
           if(l1==NULL) l1=headB;
           if(l2==NULL) l2=headA;
       }
       return l1;
    }
void addToTail(ListNode** pHead,int value){
	ListNode* pNew=new ListNode();
	pNew->m_value=value;
	pNew->m_pNext=NULL;
	if(*pHead==NULL){
		*pHead=pNew;
	}else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=NULL)
			pNode=pNode->m_pNext;
		pNode->m_pNext=pNew;
	}
}
int main(){
		ListNode *s1=new ListNode(1);
		addToTail(&s1,2);
		addToTail(&s1,3);
		addToTail(&s1,6);
		addToTail(&s1,7);
		ListNode *s2=new ListNode(4);
		addToTail(&s2,5);
		s2->m_pNext=s1->m_pNext->m_pNext->m_pNext;
		ListNode *res=getIntersectionNode(s1,s2);
		cout<<(res->m_value)<<endl;
}