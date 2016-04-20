/*
	二叉树的最低公共祖先 
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
	先来个简单点的 二叉搜索树的 
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	 TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
}
/*
	普通二叉树的 
*/
TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
    if( root == p || root == q || root == NULL)
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)
        return root;
    else
        return parent1 ? parent1:parent2;
}
/*
	普通树的 
*/
bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path){
	if(pRoot==pNode)
		return true;
	path.push_back(pRoot);
	bool found=false;
	if(pRoot->left!=NULL)
		found=GetNodePath(pRoot->left,pNode,path);
	if(!found&&pRoot->right!=NULL)
		found=GetNodePath(pRoot->right,pNode,path);
	if(!found)
		path.pop_back();
	return found;
}
TreeNode* LastCommonNode(const list<TreeNode*>& path1,
						const list<TreeNode*>& path2){
	auto iter1=path1.begin();
	auto iter2=path2.begin();
	TreeNode* pLast=NULL;
	while(iter1!=path1.end()&&iter2!=path2.end()){
		if(*iter1==*iter2)
			pLast=*iter1;
		iter1++;
		iter2++;
		
	}
	return pLast;
}
TreeNode* LastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2){
	if(pRoot==NULL||pNode1==NULL||pNode2==NULL)
		return NULL;
	list<TreeNode*> path1;
	GetNodePath(pRoot,pNode1,path1);
	list<TreeNode*> path2;
	GetNodePath(pRoot,pNode2,path2);
	
	return LastCommonNode(path1,path2);
}
int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->left->left=new TreeNode(5);
	cout<<(LastCommonParent(root,root->left->left,root->right)->val)<<endl;
}