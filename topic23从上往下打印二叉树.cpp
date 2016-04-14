/*
	�������´�ӡ����������ÿ����㣬ͬһ��Ľ��
	���մ����Ҵ�ӡ�� 
*/
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
	���нⷨ���������ȸ��ڵ����
	Ȼ�����һ���ڵ�ֵ����������ӽڵ� 
*/
void visit(TreeNode* root){
	if(root==NULL)
		return ;
	deque<TreeNode*> deq;
	deq.push_back(root);
	while(!deq.empty()){
		TreeNode* tmp=deq.front();
		deq.pop_front();
		cout<<tmp->val<<endl;
		if(tmp->left)
			deq.push_back(tmp->left);
		if(tmp->right)
			deq.push_back(tmp->right);
	}	
}
/*
	����ʹ�õݹ飬���������ʽ���£�
		3
	   / \
	  9  20
	    /  \
	   15   7
    [
	  [3], 
	  [9,20],
	  [15,7]
	] 
	ע�⣬����洢ֵ��˳����ʵ������Ľⷨ��һ�� 
*/
vector<vector<int>> ret;
void visitWithRec(TreeNode* root,int depth){
	if(root==NULL)
		return;
	if(ret.size()==depth)
		ret.push_back(vector<int>());
	ret[depth].push_back(root->val);
	visitWithRec(root->left,depth+1);
	visitWithRec(root->right,depth+1); 
}
/*
	��չһ��:
		���Ҫ������һ����ǰ����أ�
	    3
	   / \
	  9  20
	    /  \
	   15   7
	[
	  [15,7],
	  [9,20],
	  [3]
	] 
		��vector����һ�¾Ϳ�����
		reverse(ret.begin(),ret.end());
		����ı�ԭ����ret�أ�
		�½�һ����
		vector<vector<int>> res(ret.rbegin(),ret.rend()); 
*/
/*
	������չ���������ı���������
	ǰ�к󣬸��ݸ��ڵ�ı���˳���
	�����󣬸�����
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
    return [1,3,2].
    
	ǰ�򣺸�������
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
    return [1,2,3].
	�������ң��� 
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
	return [3,2,1].
	����ʵ��һ�� 
*/
/*
	���������ʹ�ö�ջ�����ı�ԭ���� 
	�򵥵��߼�����
	��������ջ��NULL
	���������ջ������������ջ 
*/
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *pCur=root;
        
        while(!stk.empty()||pCur!=NULL)
        {
        	if(pCur!=NULL){
        		stk.push(pCur);
        		pCur=pCur->left;
        	}else{
        		TreeNode *pNode=stk.top();
        		res.push_back(pNode->val);
        		stk.pop();
        		pCur=pNode->right;
        	}
        }
       	return res;
}
/*
	ǰ����� �� �� �� 
*/
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *temp=stk.top();
            res.push_back(temp->val);
            stk.pop();
            if(temp->right!=NULL)
                stk.push(temp->right);
            if(temp->left!=NULL)
                stk.push(temp->left);
        }
        return res;
}
/*
	������� �� ��  ��
	���˳���ǰ���෴
	�����溯�����صĽṹreverse�Ϳ���
	����ֱ���ڲ����ʱ��ͷ�������� 
*/
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *p=NULL;
        while(!stk.empty())
        {
            p=stk.top();
            stk.pop();
            res.insert(res.begin(),p->val);
            if(p->left) stk.push(p->left);
            if(p->right) stk.push(p->right);
        }
        return res;
    }
int main(){
	TreeNode* root=new TreeNode(8);
	root->left=new TreeNode(7);
	root->right=new TreeNode(1);
	visitWithRec(root,0);
	for(auto i:ret){
		for(auto j:i)
		 cout<<j<<endl;
	}
	visit(root);
	
	TreeNode* travel=new TreeNode(1);
	travel->right=new TreeNode(2);
	travel->right->left=new TreeNode(3);
	vector<int> travelRes;
	travelRes=inorderTraversal(travel);
	cout<<"inorder Test"<<endl;
	for(auto i:travelRes)
		cout<<i<<endl;
	travelRes=preorderTraversal(travel);
	cout<<"preorder Test"<<endl;
	for(auto i:travelRes)
		cout<<i<<endl;
	travelRes=postorderTraversal(travel);
	cout<<"post Test"<<endl;
	for(auto i:travelRes)
		cout<<i<<endl;
	
}