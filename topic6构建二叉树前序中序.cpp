/*
	输入某二叉树的前序遍历和中序遍历结果，
	重建该二叉树，结果不含重复数字，输出该二叉树的头结点 
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
	函数说明：
		首先回忆一下前序和中序
		前序为中   		左   	 右 中序为左   		中   		右 
		对应  ps  ps+pos-is      pe 	  is        pos         ie
		
		左子树的分支区间为：
			中-》左 ps+1--------ps+pos-is
			左-》中 is----------ps-1
		右子树的分支区间为：
			左-》右 pe-（ie-pos）+1----pe
			中-》右 pos+1--------------ie
		先从前序开始，找根节点，然后找中序中对应的节点
		根据中序中找到的位置划分左右子树。 		  	
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