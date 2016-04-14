/*
	从上往下打印出二叉树的每个结点，同一层的结点
	按照从左到右打印。 
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
	队列解法，迭代，先根节点入队
	然后输出一个节点值，入队两个子节点 
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
	这里使用递归，结果保存形式如下：
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
	注意，这里存储值的顺序其实和上面的解法不一样 
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
	拓展一下:
		如果要求从最后一层往前输出呢？
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
		把vector反向一下就可以了
		reverse(ret.begin(),ret.end());
		不想改变原来的ret呢？
		新建一个嘛
		vector<vector<int>> res(ret.rbegin(),ret.rend()); 
*/
/*
	接着扩展，二叉树的遍历有三种
	前中后，根据根节点的遍历顺序分
	中序：左，根，右
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
    return [1,3,2].
    
	前序：根，左，右
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
    return [1,2,3].
	后序：左，右，根 
	Given binary tree {1,#,2,3},
	   1
	    \
	     2
	    /
	   3
	return [3,2,1].
	现在实现一下 
*/
/*
	中序遍历，使用堆栈并不改变原数据 
	简单的逻辑就是
	左子树入栈到NULL
	输出根，出栈根，右子树入栈 
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
	前序遍历 中 左 右 
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
	后序遍历 左 右  根
	这个顺序和前序相反
	把上面函数返回的结构reverse就可以
	这里直接在插入的时候就反序插入了 
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