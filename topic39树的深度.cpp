/*
	输入一个二叉树的根节点，求树的深度
	从根节点到叶子节点依次经过的节点为树的一条路径，最长路径为深度
	追加 判断是否为平衡树 
*/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int TreeDepth(TreeNode* root){
	if(root==NULL)
		return 0;
	int left=TreeDepth(root->left);
	int right=TreeDepth(root->right);
	return (left>right)?(left+1):(right+1);
}
int maxDepth(TreeNode* root){
	return root==NULL?0:max(maxDepth(root->left),maxDepth(root->right))+1;
}
bool isBalanced(TreeNode* root){
	if(root == NULL)
		return true;
	int left=maxDepth(root->left);
	int right=maxDepth(root->right);
	
	return abs(left-right)<=1&&isBalanced(root->left)&&isBalanced(root->right);
}
bool isBalanced(TreeNode* root,int *depth){
	if(root==NULL){
		*depth=0;
		return true;
	}
	int left,right;
	if(isBalanced(root->left,&left)&&isBalanced(root->right,&right)){
		int diff=left-right;
		if(abs(diff)<=1){
			*depth=1+(left>right?left:right);
			return true;
		}
	}
	return false ;
}
 int dfsHeight(TreeNode *root)
{
	if(root==NULL) return 0;
	int leftHeight=dfsHeight(root->left);
	if(leftHeight==-1) return -1;
	int rightHeight=dfsHeight(root->right);
	if(rightHeight==-1) return -1;
	
	if(abs(leftHeight-rightHeight)>1) return -1;
	return max(leftHeight,rightHeight)+1;
}
/*
	求最小路径呢 
*/
int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
}
int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->left->left=new TreeNode(5);
	cout<<TreeDepth(root)<<endl;
	cout<<maxDepth(root)<<endl;
	int depth=0;
	cout<<isBalanced(root,&depth)<<endl;
	cout<<isBalanced(root)<<endl;
	cout<<(dfsHeight(root)!=-1)<<endl;
}