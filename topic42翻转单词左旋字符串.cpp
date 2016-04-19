/*
	输入一个英文句子 翻转句中单词的顺序，单词内字符顺序不变
	i am a student --->student a am i 
*/
/*
	追加 字符串的左旋就是把字符串前面的若干字符移到尾部。
	输入abcdefg,2返回左旋cdefgab 
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std; 
/*
	先整体反转
	然后根据空格划分，反转每一个单词 
*/
void reverseWords(string &s) {
       
        reverse(s.begin(),s.end());
        size_t start=0;
        size_t end=0;
        int i=0;
        while(s[0]==' ')
            s=s.erase(0,1);
        //这里以空格为分界线 为了统一代码 尾缀加了一个空格 
        s+=' ';
        for(int i=0;i<s.size();++i){
            if(s[i]!=' ')
                end++;
        //处理多空格的情况 
            while(s[i]==' '&&i<s.size()-1&&s[i+1]==' ')
                s.erase(i,1);
            if(s[i]==' '){
                if(end>start){
                    reverse(s.begin()+start,s.begin()+end);
                    start=++end;
                }
            }
        }
        s.erase(s.size()-1,1);
}
/*
	如果不要求in-place 可以用stringstream 
*/
void reverseAgain(string &s){
	istringstream is(s);
	string tmp="";
	string res="";
	while(is>>tmp){
		tmp+=" ";
		tmp+=res;
		res=tmp;
	}
	s=res.erase(res.size()-1,1);
}
/*
	借鉴stl中的rotate 
*/
void leftRotate(string & s,int n){
	int size=s.size();
	int begin=0;
	for(;n=n%size;size-=n,begin+=n){
		for(int i=0;i<n;++i)
			swap(s[begin+i],s[begin+size-n+i]);
			cout<<s<<endl;
	}
}
int main(){
	string str="i am student";
	cout<<str.size()<<endl;
	reverseWords(str);
	cout<<str<<endl;
	reverseAgain(str);
	cout<<str<<endl;
	string rot="abcdefg";
	leftRotate(rot,3);
	cout<<str<<endl;
}