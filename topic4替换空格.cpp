/*
	将字符串的空格替换为%20
	这道题目是有一点背景的，在url进行编码的时候
	只允许字母数字和特殊字符，空格的编码为%20 
*/
#include <string>
#include <iostream>
using namespace std;
/*
	函数说明：
		如果从前往后正常的进行替换，需要多次的向后移动字符串来腾出空格的空间。
		提前计算所需要的空间，resize一下，然后从后往前进行，避免多次移动。
		同时使用两个索引，一个为原字符串末尾，一个为新字符串末尾，起到检测空格
		并提前结束的作用。 
*/
void replaceStr(string &str){
	if(str.empty())
		return ;
	int oldLen=str.size();
	int numOfBlank=0;
	for(int i=0;i<oldLen;++i)
		if(str[i]==' ')
			numOfBlank++;
	int newLen=oldLen+numOfBlank*2;
	cout<<newLen<<endl;
	int indexOld=oldLen-1;
	int indexNew=newLen-1;
	str.resize(newLen);
	while(indexOld>=0&&indexNew	>indexOld){
		if(str[indexOld]==' '){
			str[indexNew--]='0';
			str[indexNew--]='2';
			str[indexNew--]='%';	
		}else{
			str[indexNew--]=str[indexOld];
		}
		--indexOld;	
	}
}
int main(){
	string s1("aa bb cc");
	cout<<s1.size()<<endl;
	replaceStr(s1);
	cout<<s1<<endl;
}
