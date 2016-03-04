/*
	反转链表 
*/
#include <list>
#include <stack>
#include <iostream>
using namespace std;
struct ListNode{
	int m_value;
	ListNode* m_pNext;
};
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
/*
	函数说明：
		首先是迭代模式的实现
		检查一下是否为空或者只有一个节点
		然后注意需要保存pre和cur两个指针
		先创建一个next指针防止丢失下一个节点的路径
		然后依次递增pre和cur 
*/
ListNode* reverseList(ListNode *pHead){
	if(pHead==NULL||pHead->m_pNext==NULL)
		return pHead;
	ListNode* pre=NULL;
	ListNode* cur=pHead;
	while(cur!=NULL){
		ListNode* next=cur->m_pNext;
		cur->m_pNext=pre;
		pre=cur;
		cur=next;
	}
	return pre;
}
/*
	下面使用使用递归 
*/
ListNode* reverseListRecur(ListNode *pHead){
	if(pHead==NULL||pHead->m_pNext==NULL)
		return pHead;
	ListNode* node=reverseListRecur(pHead->m_pNext);
	pHead->m_pNext->m_pNext=pHead;
	pHead->m_pNext=NULL;
	return node;
}
/*
	现在要求只反转某一范围内
	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,
	
	return 1->4->3->2->5->NULL. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL) return NULL;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        for(int i=0;i<m-1;++i) pre=pre->next;
        ListNode *slow=pre->next;
        ListNode *fast=slow->next;
        for(int i=0;i<n-m;++i)
        {
        	slow->next=fast->next;
        	fast->next=pre->next;
        	pre->next=fast;
        	fast=slow->next;
        }
        return dummy->next;

}
int main(void){
	ListNode *s1=new ListNode();
	cout<<s1->m_value<<endl;
	for(int i=1;i<10;++i)
		addToTail(&s1,i);
	//cout<<s1->m_value<<endl;
//	ListNode* s2=reverseList(s1);
//	while(s2!=NULL){
//		cout<<s2->m_value<<endl;
//		s2=s2->m_pNext;	
//	}
	ListNode* s3=reverseListRecur(s1);
	while(s3!=NULL){
		cout<<s3->m_value<<endl;
		s3=s3->m_pNext;	
	}
}