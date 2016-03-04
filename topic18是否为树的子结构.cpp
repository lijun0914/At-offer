/*
	输入两棵二叉树A和B，判断B是不是A的子结构。
	 
*/
#include <iostream>
using namespace std;
struct BinaryTreeNode{
	int 		val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x):val(x),left(NULL),right(NULL){
		
	}
};
bool hasTree(BinaryTreeNode* fat,BinaryTreeNode* son){
	if(son==NULL)
		return true;
	if(fat==NULL)
		return false;
	if(fat->val!=son->val)
		return false;
	return hasTree(fat->left,son->left)&&hasTree(fat->right,son->right);
}
bool isSon(BinaryTreeNode* fat,BinaryTreeNode* son){
	bool result=false;
	if(fat!=NULL&&son!=NULL){
		if(fat->val==son->val)
			result=hasTree(fat,son);
		if(!result)
			result=isSon(fat->left,son);
		if(!result)
			result=isSon(fat->right,son);
	}
	return result;

}
int main(){
	BinaryTreeNode *root=new BinaryTreeNode(8);
	root->left=new BinaryTreeNode(6);
	root->right=new BinaryTreeNode(7);
	root->left->left=new BinaryTreeNode(5);
	BinaryTreeNode *son=new BinaryTreeNode(6);
	son->left=new BinaryTreeNode(5);
	BinaryTreeNode* notSon=new BinaryTreeNode(6);
	notSon->left=new BinaryTreeNode(6);
	cout<<isSon(root,son)<<endl;
	cout<<isSon(root,notSon)<<endl;
}