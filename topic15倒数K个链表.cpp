/*
	输入一个链表，输出该链表的倒数第K个节点
	从1开始计数 
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
		fast指针先走K步，然后slow开始跟进
		最后fast到结尾时，slow即为倒数第K个 
*/
ListNode* findKtoTail(ListNode* pHead, int k){
	if(pHead==NULL||k==0)
		return NULL;
	ListNode* fast=pHead;
	ListNode* slow=pHead;
	while(k-->0){
		if(fast->m_pNext!=NULL)
			fast=fast->m_pNext;
		else
			return NULL;
	}
	while(fast!=NULL){
		fast=fast->m_pNext;
		slow=slow->m_pNext;
	}
	return slow;
}
/*
	上面要求的是寻找第K个，现在要求删除倒数第K个，要求一遍过 
	19. Remove Nth Node From End of List
	Given linked list: 1->2->3->4->5, and n = 2.
    
	After removing the second node from the end, 
	the linked list becomes 1->2->3->5.
    
	Note:
	Given n will always be valid.
	Try to do this in one pass. 
*/
/*
	函数说明：
		这里的思路延续上一个函数，让一个链表节点先行 
		但是不同的是，第二个使用的是指向链表指针的指针 
		返回头结点 
*/
ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i)
        {
            t2 = t2->m_pNext;
        }
        while(t2->m_pNext != NULL)
        {
            t1 = &((*t1)->m_pNext);
            t2 = t2->m_pNext;
        }
        *t1 = (*t1)->m_pNext;
        return head;
    }
/*
	这里可以写一个跟第一个函数一致的解法 
*/    
ListNode* removeNthFromEndTwo(ListNode* head, int n) {
        struct ListNode* front = head;
        struct ListNode* behind = head;
        
        while (front != NULL) {
            front = front->m_pNext;
            if (n-- < 0) behind = behind->m_pNext;
        }
        if (n == 0) head = head->m_pNext;
        else behind->m_pNext = behind->m_pNext->m_pNext;
        return head;
} 
/*
	拓展一下，删除所有值为val的元素
	203. Remove Linked List Elements 
*/
 ListNode* removeElements(ListNode* head, int val) {
 	ListNode* pre=new ListNode();
	pre->m_pNext=head;
	ListNode* tmp=head;
	while(tmp!=NULL){
		if(tmp->m_pNext&&(tmp->m_pNext->m_value==val))
			tmp->m_pNext=tmp->m_pNext->m_pNext;
		else
			tmp=tmp->m_pNext;
	}
	return pre->m_pNext;       
 }
int main(void){
	ListNode *s1=new ListNode();
	for(int i=1;i<10;++i)
		addToTail(&s1,i);
	ListNode *s2=findKtoTail(s1,1);
	cout<<s2->m_value<<endl;
    s2=removeNthFromEnd(s1,10);
	cout<<s2->m_value<<endl;
	s2=removeElements(s1,1);
	cout<<s2->m_pNext->m_value<<endl;
}