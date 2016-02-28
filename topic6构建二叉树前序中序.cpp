/*
	����ĳ��������ǰ�������������������
	�ؽ��ö���������������ظ����֣�����ö�������ͷ��� 
*/
#include <vector>
#include <iostream>
using namespace std;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
/*
	����˵����
		���Ȼ���һ��ǰ�������
		ǰ��Ϊ��   		��   	 �� ����Ϊ��   		��   		�� 
		��Ӧ  ps  ps+pos-is      pe 	  is        pos         ie
		
		�������ķ�֧����Ϊ��
			��-���� ps+1--------ps+pos-is
			��-���� is----------ps-1
		�������ķ�֧����Ϊ��
			��-���� pe-��ie-pos��+1----pe
			��-���� pos+1--------------ie
		�ȴ�ǰ��ʼ���Ҹ��ڵ㣬Ȼ���������ж�Ӧ�Ľڵ�
		�����������ҵ���λ�û������������� 		  	
*/
BinaryTreeNode* buildTree(vector<int> &pre,vector<int> &order,int ps,int pe,int is,int ie){
	if(ps>pe)
		return NULL;
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=pre[ps];
	int pos;
	for(int i=is;i<ie;++i){
		if(order[i]==root->m_nValue){
			pos=i;
			break;
		}	
	}
	root->m_pLeft=buildTree(pre,order,ps+1,ps+pos-is,is,pos-1);
	root->m_pRight=buildTree(pre,order,pe-(ie-pos)+1,pe,pos+1,ie);
	return root;	
}

BinaryTreeNode* build(vector<int> &pre,vector<int> &order){
	return buildTree(pre,order,0,pre.size()-1,0,order.size()-1);
}
int main(){
	
}