/*
	输入一个二叉树和一个整数，打印出二叉树中结点值的和为该整数的
	路径。从树的根往下一直到叶结点为一条路径。 
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
/*
	这个一个典型的回溯问题
	其实跟前一个中序遍历的思想差不多
	差别就在于末尾的pop
	 
*/
void print(TreeNode* root,vector<int>& res,int leave){
	if(root==NULL)
		return;
	res.push_back(root->val);
	if(!(root->left)&&!(root->right)&&leave==root->val){
		for(auto i:res)
			cout<<i<<" ";
		cout<<endl;
	} 
	print(root->left,res,leave-root->val);
	print(root->right,res,leave-root->val);	
	res.pop_back();
	
	
}
/*
	如果不需要记录 输出，直接判断呢？ 
*/
bool hasPathSum(TreeNode* root,int sum){
	if(root==NULL) return false;
	if(!(root->left)&&!(root->right)&&sum==root->val)
		return true;
	return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
}
int main(){
	TreeNode* root=new TreeNode(10);
	root->left=new TreeNode(5);
	root->right=new TreeNode(12);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(7);
	cout<<hasPathSum(root,22)<<endl;
	cout<<hasPathSum(root,222)<<endl;
	vector<int> res;
	print(root,res,22);
	print(root,res,9);
}