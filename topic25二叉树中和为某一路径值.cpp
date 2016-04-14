/*
	����һ����������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������
	·���������ĸ�����һֱ��Ҷ���Ϊһ��·���� 
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
	���һ�����͵Ļ�������
	��ʵ��ǰһ�����������˼����
	��������ĩβ��pop
	 
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
	�������Ҫ��¼ �����ֱ���ж��أ� 
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