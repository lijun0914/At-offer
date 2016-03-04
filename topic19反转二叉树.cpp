/*
	输入一个二叉树，输出它的镜像
	 4						
   /   \
  2     7
 / \   / \
1   3 6   9

     4
   /   \
  7     2
 / \   / \
9   6 3   1 
*/
#include <iostream>
#include <stack>
#include <deque>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* invertTree(TreeNode* root){
	if(root->left==NULL&&root->right==NULL)
		return NULL;
	TreeNode* tmp=root->left;
	root->left=root->right;
	root->right=tmp;
	if(root->left)
		invertTree(root->left);
	if(root->right);
		invertTree(root->right);
	return root;
}
/*more clean*/ 
TreeNode* invertTree2(TreeNode* root){
	if(root){
		invertTree2(root->left);
		invertTree2(root->right);
		std::swap(root->left,root->right);
	}
	return root;
}
/*Non Recusive*/
TreeNode* invertTree3(TreeNode* root){
	stack<TreeNode*> stk;
	stk.push(root);
	while(!stk.empty()){
		TreeNode* p=stk.top();
		stk.pop();
		if(p){
			stk.push(p->left);
			stk.push(p->right);
			swap(p->left,p->right);
		}
	}
	return root;	
}
void visit(TreeNode* root){
	if(root==NULL)
		return ;
	deque<TreeNode*> treeDq;
	treeDq.push_back(root);
	while(!treeDq.empty()){
		TreeNode* tmp=treeDq.front();
		cout<<tmp->val<<endl;
		treeDq.pop_front();
		if(tmp->left){
			treeDq.push_back(tmp->left);
		}
		if(tmp->right){
			treeDq.push_back(tmp->right);
		}
	}
}
int main(){
	TreeNode* root=new TreeNode(8);
	root->left=new TreeNode(7);
	root->right=new TreeNode(1);
	root=invertTree3(root);
	visit(root);	
}