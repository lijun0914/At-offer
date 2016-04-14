/*
	输入一个字符串，打印出该字符串的所有排列。例如输入
	abc,则打印出abc,acb,bac,cab,cba 
*/

#include<iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
//递归交换 
void print(char *str,char *begin){
	if(*begin=='\0'){
		cout<<str<<endl;
	}else{
		for(char *p=begin;*p!='\0';p++){
			swap(*p,*begin);
			print(str,begin+1);
			swap(*p,*begin);
		}
	}
}
int main(){
	char str[]="abc";
	print(str,str);
	//使用stl自带算法完成排列 
	char elements[]={
		'a','b','c'
	};
	const size_t N=sizeof(elements)/sizeof(elements[0]);
	vector<int> vec(elements,elements+N);
	int count=0;
	do{
		cout<<++count<<":";
		copy(vec.begin(),vec.end(),
			ostream_iterator<char>(cout,", "));
		cout<<endl;
	}while(next_permutation(vec.begin(),vec.end()));
}