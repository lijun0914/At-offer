/*
	请实现函数ComplexListNode* Clone(ComplexListNode* pHead)
	复制一个复杂链表。m_pSlibling指向链表中的任意节点或者NULL 
*/
#include <iostream>
struct ComplexListNode{
	int 		val;
	ComplexListNode* next;
	ComplexListNode* slib;
};
void cloneNodes(ComplexListNode* pHead){
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL){
		ComplexListNode* tmp=new ComplexListNode();
		tmp->val=pNode->val;
		tmp->next=pNode->next;
		tmp->slib=NULL;
		
		pNode->next=tmp;
		pNode=tmp->next;
	}
}
void connectSlib(ComplexListNode* pHead){
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL){
		ComplexListNode* tmp=pNode->next;
		tmp->slib=pNode->slib->next;
		pNode = tmp->next;
	}
}
ComplexListNode* reconnect(ComplexListNode* pHead){
	ComplexListNode* pNode=pHead;
	ComplexListNode* cloneHead=NULL;
	ComplexListNode* cloneNode=NULL;
	if(pNode!=NULL){
		cloneHead=cloneNode=pNode->next;
		pNode->next=cloneNode->next;
		pNode=pNode->next;
	}
	while(pNode!=NULL){
		cloneNode->next=pNode->next;
		cloneNode=cloneNode->next;
		pNode->next=cloneNode->next;
		pNode=pNode->next;
	}
	return cloneHead;
}
ComplexListNode* clone(ComplexListNode* pHead){
	cloneNodes(pHead);
	connectSlib(pHead);
	return reconnect(pHead);	
}
int main(){
	ComplexListNode* org=new ComplexListNode();
	org->val=1;
}
