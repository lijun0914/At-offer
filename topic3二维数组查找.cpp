/*
	在一个二维数组里，每一行都按从左到右递增
	每一列从上到下递增，实现一个函数，输入二维数组，和一个整数，
	判断是否有该整数 
*/
#include <vector>
#include <iostream>
using namespace std;

/*
	函数说明：
		从右上角开始查找，避免从左到右，从上到下的路径分支的选择 
*/
bool findNum(vector<vector<int>> mat,int number){
	bool find=false;
	int row=mat.size();
	int col=mat[0].size();
	int i=0;
	int j=col-1;
	while(i<row&&j>=0){
		if(mat[i][j]==number)
			return true;
		else if(mat[i][j]>number)
			--j;
		else
			++i;
	}
	return find;
}
int main(void){
	vector<vector<int>> a={
		{
			1,2,8,9
		},
		{
			2,4,9,12		
		},
		{
			4,7,10,13
		},{
			6,8,11,15
		}
	};
	cout<<(findNum(a,88))<<endl;
}