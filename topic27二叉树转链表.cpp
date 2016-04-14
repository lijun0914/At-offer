/*
	����һ��������������������װ����һ�������˫������
	Ҫ���ܴ����µĽڵ㣬ֻ�ܵ�������ָ�� 
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct BinaryTree{
	int val;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree(int v):val(v),left(NULL),right(NULL){
		
	}
};
/*
	�����������������+˫��������� 
*/
void ConvertNode(BinaryTree* pNode,BinaryTree** pLastNode){
	if(pNode==NULL)
		return ;
	BinaryTree* cur=pNode;
	if(cur->left!=NULL)
		ConvertNode(cur->left,pLastNode);
	cur->left=*pLastNode;
	if(*pLastNode!=NULL)
		(*pLastNode)->right=cur;
		
	*pLastNode=cur;
	
	if(cur->right!=NULL)
		ConvertNode(cur->right,pLastNode);
}
BinaryTree* Convert(BinaryTree* root){
	BinaryTree* pLastNode=NULL;
	ConvertNode(root,&pLastNode);
	BinaryTree* pHead=pLastNode;
	while(pHead!=NULL&&pHead->left!=NULL)
		pHead=pHead->left;
	return pHead;
	
}
/*
	�����Ƿǵݹ�汾 ʹ����lambda
	�ǳ�Ư���� 
*/
template <typename F>
void inorderTravel(BinaryTree* root,F visit){
	if(root==NULL) return ;
	inorderTravel(root->left,visit);
	visit(root);
	inorderTravel(root->right,visit);
}
template <typename F>
void inorderTravelNonres(BinaryTree* root,F visit){
	//ָ������� 
	BinaryTree *&cur=root;
	stack<BinaryTree*> stk;
	while(!stk.empty()||cur!=NULL){
		if(cur!=NULL){
			stk.push(cur);
			cur=cur->left;
		}else{
			BinaryTree* tmp=stk.top();
			visit(tmp);
			stk.pop();
			cur=tmp->right;
		}
	}
}
BinaryTree* BinTreeConvertLink(BinaryTree* root){
	BinaryTree guard(0);
	BinaryTree* tail=&guard;
	inorderTravelNonres(root,[&tail](BinaryTree* n){
		tail->right = n;
		n->left = tail;
		tail = n;
	});
	tail->right=0;
	if(guard.right!=0){
		guard.right->left=0;
	}
	return guard.right;
}
int main(){
	BinaryTree* root=new BinaryTree(10);
	root->left=new BinaryTree(6);
	root->right=new BinaryTree(14);
	root->left->left=new BinaryTree(4);
	root->left->right=new BinaryTree(8);
	//BinaryTree *rev=Convert(root);
	BinaryTree *rev=BinTreeConvertLink(root);
	while(rev!=NULL){
		cout<<rev->val<<endl;		
		rev=rev->right;
	}
		
}