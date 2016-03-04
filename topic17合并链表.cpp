/*
	输入两个递增排序的链表，合并这两个链表 
*/
#include <list>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode{
	int m_value;
	ListNode* m_pNext;
	ListNode(){
		
	}
	ListNode(int x):m_value(x),m_pNext(NULL){
		
	}
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
ListNode* merge(ListNode* s1,ListNode* s2){
	if(s1==NULL)
		return s2;
	else if(s2==NULL)
		return s1;
	ListNode* pHead=NULL;
	if(s1->m_value>s2->m_value){
		pHead=s2;
		pHead->m_pNext=merge(s1,s2->m_pNext);
	}else{
		pHead=s1;
		pHead->m_pNext=merge(s1->m_pNext,s2);
	}
	return pHead;
}
/*
	以上为二路归并
	现在要求合并K路 
	函数思路：
	  先取出K路链表的第一个建一个小根堆（自定义comp） 
	  然后每次从堆顶取出第一个元素插入到临时的链表
	  如果后继不为空，就把后继的元素插入到堆的末尾，调整
	  后继为空，就是正常的pop_back()，堆顶元素放到数组末尾
	  并用原来的末尾元素替换 
*/
static bool heapComp(ListNode *a,ListNode *b){
        return a->m_value>b->m_value;
}
 ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode *res=&head;
        int heapSize=lists.size();
        vector<ListNode*> heap;
        for(int i=0;i<heapSize;++i){
            if(lists[i])
                heap.push_back(lists[i]);
        }
        make_heap(heap.begin(),heap.end(),heapComp);
        while(heap.size()>0){
            res->m_pNext=heap.front();
            pop_heap(heap.begin(),heap.end(),heapComp);
            heap.pop_back();
            res=res->m_pNext;
            if(res->m_pNext){
                heap.push_back(res->m_pNext);
                push_heap(heap.begin(),heap.end(),heapComp);
            }
        }
        return head.m_pNext;
        
 }
int main(void){
	ListNode *s1=new ListNode(0);
	for(int i=1;i<10;++i)
		addToTail(&s1,i);
	ListNode *s2=new ListNode(0);
	for(int i=1;i<10;++i)
		addToTail(&s2,2*i);
//	ListNode  *s3=merge(s1,s2);
//		while(s3!=NULL){
//		cout<<s3->m_value<<endl;
//		s3=s3->m_pNext;	
//	}	
	vector<ListNode*> test;
	test.push_back(s1);
	test.push_back(s2);
	ListNode  *s4=mergeKLists(test);
		while(s4!=NULL){
		cout<<s4->m_value<<endl;
		s4=s4->m_pNext;	
	}	 
}