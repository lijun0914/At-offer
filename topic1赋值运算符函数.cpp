/*
����ΪCMyString����������Ϊ��������Ӹ�ֵ����� 
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
	���켸��֪ʶ�㣺
	1.����ֵ����Ϊ  X& ���������ֵʱ����ֵ����
	2.ʹ��const &���Ч�ʣ����⴫����ʱ�Ŀ�������
	3.�ڸ�ֵ�Ϳ������캯���У�Ӧ�����ͷ�ԭ����ռ䣬�������룬
	��������ָ��ָ��ͬһ�ڴ棬ǳ�������⣬�����ڴ�й©��
	4.����ʹ��swap��д�����ȹ���ֲ���������������֮���ͷŵ���
	5.�ַ�������ռ�ʱ��Ӧ��+1��Ϊ������'\0'��λ�á�
	6.strcpyӦ��ʹ�ø���ȫ��strncpy���棬���⻺��������� 
	 
*/
CMyString& CMyString::operator=(const CMyString& rhs){
	if(this!=&rhs){
		delete []m_pData;
		m_pData=NULL;
		m_pData=(char *)malloc(strlen(rhs.m_pData)+1);
		strcpy(m_pData,rhs.m_pData);	
		//���ù���󽻻���ֹ�쳣
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