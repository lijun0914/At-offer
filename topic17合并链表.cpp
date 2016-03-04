/*
	����������������������ϲ����������� 
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
	����Ϊ��·�鲢
	����Ҫ��ϲ�K· 
	����˼·��
	  ��ȡ��K·����ĵ�һ����һ��С���ѣ��Զ���comp�� 
	  Ȼ��ÿ�δӶѶ�ȡ����һ��Ԫ�ز��뵽��ʱ������
	  �����̲�Ϊ�գ��ͰѺ�̵�Ԫ�ز��뵽�ѵ�ĩβ������
	  ���Ϊ�գ�����������pop_back()���Ѷ�Ԫ�طŵ�����ĩβ
	  ����ԭ����ĩβԪ���滻 
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