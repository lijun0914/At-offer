/*
	���һ���࣬����ֻ�����ɸ����һ��ʵ�� 
	������ģʽ 
*/
#include<iostream>
using namespace std;
/*
	һ��ĵ���ģʽû�п��ǵ��̰߳�ȫ��
	��Ҫlock��unlock��֤���̰߳�ȫ��ͬʱʹ��˫����
	����������룬��������ʹ�� 
		if(x!=NULL){
			lock();
			if(x!=NULL)
			{
			}
			unlock();
		}
	ʵ���Ϸ�Ϊ����������ģʽ���������ǿ�ʼ�ͳ�ʼ���������ȵ���Ҫ�����ʱ��
	�������Լ�������ʱ��ų�ʼ��������
		
	�����ʵ��Ϊ����ģʽ��ֻ������Ҫ��ʱ��Ź�����
	ͬʱ�ֲ���̬�����ĳ�ʼ����֤���̰߳�ȫ��
	������lock unlock������������ʧ�� 
	
	����ڶ��������ϣ���Ҫʹ��new���Լ������ڴ���գ���Ҫ�Լ�����һ���ڲ��ࡣ
	�������£�
	class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return m_Instance;
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static Singleton *m_Instance;
	int m_Test;

	// This is important
	class GC
	{
	public :
		~GC()
		{
			// We can destory all the resouce here, eg:db connector, file handle and so on
			if (m_Instance != NULL )
			{
				cout<< "Here is the test" <<endl;
				delete m_Instance;
				m_Instance = NULL ;
			}
		}
	};
	static GC gc;
};

Singleton *Singleton ::m_Instance = new Singleton();
Singleton ::GC Singleton ::gc; 
*/
class Single{
	public:
		static Single* newInsance(){
			static Single instance;
			return &instance;
		}
		int test(){
			return number;
		}
	private:
		Single(){ number=1; }
		//static Single* instance;
		int number;
			
};
//Single* Single::instance=new Single();
int main(){
	Single* s1=Single::newInsance();
	cout<<(s1->test())<<endl;
	
	s1=Single::newInsance();
	cout<<(s1->test())<<endl;
	return 0;
}
