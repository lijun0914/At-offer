/*
	反向输出链表，链表结构如下 
	struct ListNode{
		int m_value;
		ListNode* m_pNext;
	}
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
		使用堆栈完成序列的反序。 
*/
void printList(ListNode* pHead){
	std::stack<ListNode*> nodes;
	ListNode* pNode=pHead;
	while(pNode!=NULL){
		nodes.push(pNode);
		pNode=pNode->m_pNext;		
	}
	while(!nodes.empty()){
		pNode=nodes.top();
		cout<<pNode->m_value<<endl;
		nodes.pop();
	}
}
/*
	函数说明：
		上面的代码明确的申请了堆栈
		这里使用递归，其实也是使用堆栈。 
*/
void printListCy(ListNode *pHead){
	if(pHead!=NULL){
		if(pHead->m_pNext!=NULL){
			printListCy(pHead->m_pNext);
		}
		cout<<pHead->m_value<<endl;
	}
}
int main(){
	ListNode *s1=new ListNode();
	for(int i=1;i<10;++i)
		addToTail(&s1,i);
	printListCy(s1);
	printList(s1);
}
