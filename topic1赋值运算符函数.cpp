/*
如下为CMyString的声明，请为该类型添加赋值运算符 
*/
#include<iostream>
#include<string.h>
class CMyString{
	public:
		CMyString(char *m_pData=NULL);
		CMyString(const CMyString& str);
		~CMyString(void);
	    CMyString& operator=(const CMyString& rhs);
	private: 
		char * m_pData;
};
/*
	考察几个知识点：
	1.返回值类型为  X& 解决连续赋值时的左值问题
	2.使用const &提高效率，避免传参数时的拷贝构造
	3.在赋值和拷贝构造函数中，应该先释放原对象空间，重新申请，
	避免两个指针指向同一内存，浅拷贝问题，避免内存泄漏。
	4.可以使用swap的写法，先构造局部变量，在作用域之外释放掉。
	5.字符串申请空间时。应该+1，为结束符'\0'留位置。
	6.strcpy应该使用更安全的strncpy代替，避免缓冲区溢出。 
	 
*/
CMyString& CMyString::operator=(const CMyString& rhs){
	if(this!=&rhs){
		delete []m_pData;
		m_pData=NULL;
		m_pData=(char *)malloc(strlen(rhs.m_pData)+1);
		strcpy(m_pData,rhs.m_pData);	
		//可用构造后交换防止异常
	/*	CMyString strTemp(rhs);
		char *pTemp=strTemp.m_pData;
		strTemp.m_pData=m_pData;
		m_pData=pTemp;*/
	}
	return *this;
	
}

int main(void){
	return 0;
}