/*
	输入一个矩阵，按照从外到里顺时针依次打印每个
	数字
	1  2  3  4
	5  6  7  8
	9  10 11 12 
	13 14 15 16
	
	1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10 
*/
#include <vector>
#include <iostream>
using namespace std;
vector<int> print(vector<vector<int>>& matrix){
	vector<int> res;
	int rowBegin=0;
	int colBegin=0;
	int rowEnd=matrix.size()-1;
	int colEnd=matrix[0].size()-1;
	while(rowBegin<=rowEnd&&colBegin<=colEnd){
		for(int i=colBegin;i<=colEnd;++i)
			res.push_back(matrix[rowBegin][i]);
		rowBegin++;
		for(int i=rowBegin;i<=rowEnd;++i)
			res.push_back(matrix[i][colEnd]);
		colEnd--;
		if(rowBegin<=rowEnd)
			for(int i=colEnd;i>=colBegin;--i)
				res.push_back(matrix[rowEnd][i]);
		rowEnd--;
		if(colBegin<=colEnd)
			for(int i=rowEnd;i>=rowBegin;--i)
				res.push_back(matrix[i][colBegin]);
		colBegin++;
	}
	return res;
}
/*
	题目稍微变一下，讲从1到n*n放入到二维数组中
	Given an integer n, generate a square matrix filled with elements 
	from 1 to n2 in spiral order.

	For example,
	Given n = 3,
	
	You should return the following matrix:
	[
	 [ 1, 2, 3 ],
	 [ 8, 9, 4 ],
	 [ 7, 6, 5 ]
	] 
*/
vector<vector<int>> generateMatrix(int n) {
	  // Declaration
        vector<vector<int>> matrix (n,vector<int> (n));

        // Edge Case
        if (n == 0) {
            return matrix;
        }

        // Normal Case
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int num = 1; //change

        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i ++) {
                matrix[rowStart][i] = num ++; //change
            }
            rowStart ++;

            for (int i = rowStart; i <= rowEnd; i ++) {
                matrix[i][colEnd] = num ++; //change
            }
            colEnd --;

            for (int i = colEnd; i >= colStart; i --) {
                if (rowStart <= rowEnd)
                    matrix[rowEnd][i] = num ++; //change
            }
            rowEnd --;

            for (int i = rowEnd; i >= rowStart; i --) {
                if (colStart <= colEnd)
                    matrix[i][colStart] = num ++; //change
            }
            colStart ++;
        }

        return matrix;
}
int main(void){
	vector<vector<int>> mat={
		{
			1,2,3,4
		},
		{
			5,6,7,8
		},
		{
			9,10,11,12
		},
		{
			13,14,15,16
		}
	};
	vector<int> res=print(mat);
	for(auto i:res){
		cout<<i<<" ";
	}
	cout<<endl;
	vector<vector<int>> test=generateMatrix(4);
	for(vector<vector<int> >::iterator it=test.begin();it!=test.end();it++)  //判断外层循环
	{
		for(vector<int >::iterator it1=it->begin();it1!=it->end();it1++)  //判断内层循环
			cout<<*it1<<" ";
	   cout<<endl;
	}
}